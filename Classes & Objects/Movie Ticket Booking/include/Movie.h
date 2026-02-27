#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <vector>
#include "Showtime.h"

class Movie {
private:
    std::string title;
    std::string duration;
    std::string rating;
    std::vector<Showtime> showtimes;

public:
    Movie(std::string title, std::string duration, std::string rating, std::vector<Showtime> showtimes);

    std::string getTitle() const;
    std::string getDuration() const;
    std::string getRating() const;
    std::vector<Showtime> getShowtimes() const;
    
    void information();
};

#endif