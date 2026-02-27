#include <iostream>
#include <iomanip>
#include <numeric>
#include "../../include/Movie.h"
#include "../../include/Showtime.h"

Movie::Movie(std::string title, std::string duration, std::string rating, std::vector<Showtime> showtimes) 
    : title(title), duration(duration), rating(rating), showtimes(showtimes) {}

std::string Movie::getTitle() const {return title;}
std::string Movie::getDuration() const {return duration;}
std::string Movie::getRating() const {
    std::string rating_color;
    std::string default_color = "\033[0m";

    if (rating == "G") return "\033[32m" + rating + "\033[0m";
    else if (rating == "PG") return "\033[34m" + rating + "\033[0m";
    else if (rating == "R-13") return"\033[33m" + rating + "\033[0m";  
    else if (rating == "R-16") return "\033[1;33m" + rating + "\033[0m"; 
    else if (rating == "R-18") return "\033[31m" + rating + "\033[0m";
    
    return rating;
}
std::vector<Showtime> Movie::getShowtimes() const {return showtimes;}
    
void Movie::information() {
    std::cout << "\n\033[32mMovie Information\033[0m\n" << std::endl;
    std::cout << "Title: " << this->title << "\n";
    std::cout << "Duration: " << this->duration << "\n";
    std::cout << "Rating: " << getRating() << "\n";   
    
    std::cout << "\n" << std::left 
              << "\033[33m" << std::setw(20) << "Showtimes\033[0m" 
              << "\033[34m" << std::setw(5) << "Seats\033[0m" 
              << "\n";
    
    // separator
    std::cout << std::string(20 + 5, '-') << "\n";

    for (auto& s : showtimes) {
        int count = 0;
        for (int i = 0; i < s.getSeats().size(); i++) {
            if (!s.getSeats()[i]) count++; 
        }

        std::cout << std::left
                  << std::setw(20) << s.getTime() 
                  << std::setw(5) << count 
                  << "\n";
    }
}