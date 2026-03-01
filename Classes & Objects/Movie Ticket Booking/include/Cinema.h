#ifndef CINEMA_H
#define CINEMA_H
#include <iostream>
#include <vector>
#include "Movie.h"
#include "Ticket.h"

class Cinema {
private:
    std::vector<Movie> movies;
    std::vector<Ticket> tickets;

public:
    Cinema();

    void listMovies();
    void handleBooking(Cinema& cinema);
    Movie* selectMovie(Cinema& cinema, std::string title, int& showtime, int& seat);
    Showtime* selectShowtime(Movie& movie, int& showtime, int& seat);
    void confirmBooking(Movie* movie, Showtime* showtime, int seat);
};
#endif