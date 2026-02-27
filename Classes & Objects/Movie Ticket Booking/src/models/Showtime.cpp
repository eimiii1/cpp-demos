#include <iostream>
#include "../../include/Showtime.h"

Showtime::Showtime(std::string time, std::vector<bool> seats) 
    : time(time), seats(seats) {}

std::string Showtime::getTime() const {return time;}
const std::vector<bool>& Showtime::getSeats() const {return seats;}