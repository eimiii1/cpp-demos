#include <iostream>
#include "../../include/Ticket.h"

Ticket::Ticket(std::string movie, std::string showtime, std::string seat) 
    : movie(movie), showtime(showtime), seat(seat) {}

void Ticket::showTicket() {
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