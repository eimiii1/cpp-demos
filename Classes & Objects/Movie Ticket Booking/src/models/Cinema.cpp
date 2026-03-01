#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
#include "../../include/Cinema.h"
#include "../../include/Movie.h"
#include "../../include/Showtime.h"

Cinema::Cinema() {
    Movie movie1("The Loved One", "1h 40m", "R-13", 
        std::vector<Showtime>{Showtime("10:00 AM", std::vector<bool>(10, false)), Showtime("2:00 PM", std::vector<bool>(20, false))});
    Movie movie2("Until She Remembers", "1h 47m", "PG", 
        std::vector<Showtime>{Showtime("10:00 AM", std::vector<bool>(15, false)), Showtime("3:00 PM", std::vector<bool>(15, false))});
    Movie movie3("Scream 7", "1h 54m", "R-16",
        std::vector<Showtime>{Showtime("10:00 AM", std::vector<bool>(20, false)), Showtime("2:00 PM", std::vector<bool>(10, false))});

    movies.push_back(movie1);
    movies.push_back(movie2);
    movies.push_back(movie3);
}

void Cinema::listMovies() {
    std::cout << "\n" << std::left
              << "\033[34m" << std::setw(25) << "Title" << "\033[0m"
              << "\033[35m" << std::setw(15) << "Duration" << "\033[0m"
              << "\033[36m" << std::setw(10) << "Rating" << "\033[0m"
              << "\n";

    std::cout << std::string(25 + 15 + 10, '-') << "\n";

    for (auto& m : movies) {
        std::cout << std::left 
                  << std::setw(25) << m.getTitle()
                  << std::setw(15) << m.getDuration()
                  << std::setw(10) << m.getRating()
                  << "\n";
    }
}

// Menu helper
void booking_menu() {
    std::string arr[2] = {"Select Movie", "Confirm Booking"};
    std::cout << "\n";
    for (int i = 0; i < 2; i++) {
        std::cout << i+1 << ". " << arr[i] << "\n";
    }
}

// Movie input
void inputMovie(int& showtime, int& seat) {
    std::cout << "\nSelect showtime: ";
    std::cin >> showtime;

    std::cout << "Select seat: ";
    std::cin >> seat;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Handle booking
void Cinema::handleBooking(Cinema& cinema) {
    Movie* selectedMovie = nullptr;
    Showtime* selectedShowtime = nullptr;
    int selectedSeat = 0;
    int selectedShowtimeIndex = 0;

    while (true) {
        booking_menu();
        std::cout << "\nChoice: ";
        int choice;
        std::cin >> choice;

        #ifdef _WIN32
            system("cls");
        #else 
            system("clear");
        #endif
        
        switch (choice) {
            case 1: {
                listMovies();

                std::string movieName;
                std::cout << "\nSelect movie: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, movieName);

                selectedMovie = selectMovie(cinema, movieName, selectedShowtimeIndex, selectedSeat);
                if (!selectedMovie) {
                    std::cout << "Movie not found!\n";
                    break;
                }

                selectedShowtime = selectShowtime(*selectedMovie, selectedShowtimeIndex, selectedSeat);
                if (!selectedShowtime) {
                    std::cout << "Invalid showtime or seat already taken!\n";
                    selectedMovie = nullptr;
                    selectedSeat = 0;
                }
            }
            break;

            case 2: {
                if (!selectedMovie || !selectedShowtime) {
                    std::cout << "No movie or showtime selected yet!\n";
                    break;
                }
                confirmBooking(selectedMovie, selectedShowtime, selectedSeat);
            std::cout << "\n\033[31mThank you for watching.\033[0m\n" << std::endl;
            std::exit(0);
            }
            break;

            default:
                std::cout << "Invalid choice!\n";
        }
    }
}

// Select movie
Movie* Cinema::selectMovie(Cinema& cinema, std::string movieName, int& showtime, int& seat) {
    for (auto& m : movies) {
        if (m.getTitle() == movieName) {
            m.information();
            inputMovie(showtime, seat);
            return &m; // pointer to real movie
        }
    }
    return nullptr;
}

// Select showtime and seat (vector<bool> fix applied)
Showtime* Cinema::selectShowtime(Movie& movie, int& showtime, int& seat) {
    int st_index = showtime - 1;
    if (st_index < 0 || st_index >= movie.getShowtimes().size()) return nullptr;

    auto& st = movie.getShowtimes()[st_index]; // reference to actual showtime

    int s_index = seat - 1;
    if (s_index < 0 || s_index >= st.getSeats().size()) return nullptr;

    bool current = st.getSeats()[s_index]; // copy from vector<bool>
    if (current) return nullptr;           // seat already taken

    st.getSeats()[s_index] = true;        // mark as taken
    return &st;
}

// Confirm booking display
void Cinema::confirmBooking(Movie* movie, Showtime* showtime, int seat) {
    std::cout << "\n\033[32mBooking Confirmed!\033[0m\n";
    std::cout << "\033[34mTitle: \033[0m" << movie->getTitle() << "\n";
    std::cout << "\033[35mDuration: \033[0m" << movie->getDuration() << "\n";
    std::cout << "\033[36mRating: \033[0m" << movie->getRating() << "\n";
    std::cout << "\033[33mShowtime: \033[0m" << showtime->getTime() << "\n";

    std::cout << "\n\033[34mSeats:\033[0m\n";
    auto& seats = showtime->getSeats();
    for (size_t i = 0; i < seats.size(); i++) {
        if ((int)i == seat - 1) {
            std::cout << "\033[32m☑\033[0m "; // your booked seat
        } else {
            std::cout << (seats[i] ? "\033[31m☑\033[0m " : "\033[32m☐\033[0m ");
        }
        if ((i + 1) % 5 == 0) std::cout << "\n";
    }
    std::cout << "\n";
}