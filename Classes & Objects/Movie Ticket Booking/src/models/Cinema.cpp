#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
#include "../../include/Cinema.h"
#include "../../include/Movie.h"
#include "../../include/Showtime.h"

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

void Cinema::handleBooking() {
    std::cout << "\n\033[31mBook a Ticket\033[0m\n" << std::endl;
    booking_menu();
    int choice;
    
    std::cout << "\nChoice: ";
    std::cin >> choice;
    
    switch (choice) {
        case 1: {
            listMovies();
            std::string movie;
            std::cout << "\nSelect movie: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, movie);
            selectMovie(movie);
        }
    }
}

void Cinema::selectMovie(std::string movie) {
    for (auto& m : movies) {
        if (m.getTitle() == movie) {
            m.information();
        }
    }
}

void Cinema::selectShowTime(std::string st) {

}


void booking_menu() {
    int option;
    std::string arr[4] = {
        "Select Movie",
        "Select Showtime",
        "Select Seat",
        "Confirm Booking"
    };
    
    int menu_length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < menu_length; i++) {
        std::cout << i+1 << ". " << arr[i] << "\n";
    }
}