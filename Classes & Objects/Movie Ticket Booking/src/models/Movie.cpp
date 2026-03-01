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
std::vector<Showtime>& Movie::getShowtimes() {return showtimes;}
    
void Movie::information() {
    std::cout << "\n\033[32mMovie Information\033[0m\n";
    std::cout << "Title: " << this->title << "\n";
    std::cout << "Duration: " << this->duration << "\n";
    std::cout << "Rating: " << getRating() << "\n";   
    
    std::cout << "\n\033[34mShowtimes\033[0m\n";
    for (int i = 0; i < showtimes.size(); i++) {
        std::cout << "\033[36m" << i+1 << ". " << showtimes[i].getTime() << "\033[0m\n";

        for (int j = 0; j < showtimes[i].getSeats().size(); j++) {
            std::cout << (!showtimes[i].getSeats()[j] ? "\033[32m☐\033[0m" : "\033[31m☑\033[0m") << " ";
            if ((j+1) % 5 == 0) std::cout << "\n";
            if (j >= showtimes[i].getSeats().size() - 1) std::cout << "\n";
        }
    }
    
}