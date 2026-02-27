#ifndef CINEMA_H
#define CINEMA_H
#include <iostream>
#include <vector>
#include "Movie.h"

class Cinema {
private:
    std::vector<Movie> movies;
public:
    Cinema();

    void listMovies();
    void handleBooking();
    void selectMovie(std::string title);
    void selectShowTime(std::string st);
    void selectSeat(int s);

    void listShowtimes(std::vector<Movie>& movies, std::string movie);
    void listSeats(std::vector<Showtime>::iterator it);
};
#endif