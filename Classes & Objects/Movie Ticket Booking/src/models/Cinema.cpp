#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
#include "../../include/Cinema.h"
#include "../../include/Movie.h"
#include "../../include/Showtime.h"
#include "../../include/Ticket.h"

Cinema::Cinema() {
    // create 3 instances of movies (movie list in the cinema)
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
    
    // separator
    std::cout << std::string(20 + 15 + 10, '-') << "\n";

    for (auto& m : movies) {
        std::cout << std::left 
                  << std::setw(25) << m.getTitle()
                  << std::setw(15) << m.getDuration()
                  << std::setw(10) << m.getRating()
                  << "\n";
    }
}

void booking_menu();
void inputMovie(int& showtime, int& seat);
void handleMovie(Cinema& cinema, Movie& movie, int& showtime, int& seat);

void Cinema::handleBooking(Cinema& cinema) {
    std::cout << "\n\033[31mBook a Ticket\033[0m\n" << std::endl;
    int choice;

    Movie* temp;

    
    while (true) {
        booking_menu();
        std::cout << "\nChoice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                listMovies();
                std::string movie;
                std::cout << "\nSelect movie: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, movie);
                temp = selectMovie(cinema, movie);
            }
            break;

            case 2: confirmBooking(temp); break;
        }
    }
}

void booking_menu() {
    int option;
    std::string arr[2] = {
        "Select Movie",
        "Confirm Booking"
    };
    
    int menu_length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < menu_length; i++) {
        std::cout << i+1 << ". " << arr[i] << "\n";
    }
}

Movie* Cinema::selectMovie(Cinema& cinema, std::string movie) {
    int showtime;
    int seat;

    for (auto& m : movies) {
        if (m.getTitle() == movie) {
            m.information();
            inputMovie(showtime, seat);
            handleMovie(cinema, m, showtime, seat);
            return &m;
        }
    }
    return nullptr;
}

void inputMovie(int& showtime, int& seat) {
    std::cout << "\nSelect showtime: ";
    std::cin >> showtime;

    std::cout << "Select seat: ";
    std::cin >> seat;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void handleMovie(Cinema& cinema, Movie& movie, int& showtime, int& seat) {
    cinema.selectShowtime(showtime);
    cinema.selectSeat(seat);
}

int Cinema::selectShowtime(int& showtime) {
    return showtime;
}

int Cinema::selectSeat(int& seat) {
    return seat;
}

void Cinema::confirmBooking(Movie* movie) {
    std::cout << "\033[32mMovie Information\033[0m\n";
    std::cout << "\033[34mTitle: \033[0m" << movie->getTitle() << "\n";
    std::cout << "\033[35mDuration: \033[0m" << movie->getDuration() << "\n";
    std::cout << "\033[36mRating: \033[0m" << movie->getRating() << "\n";
}