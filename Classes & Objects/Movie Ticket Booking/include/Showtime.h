#ifndef SHOWTIME_H
#define SHOWTIME_H
#include <iostream>
#include <vector>

class Showtime {
private:
    std::string time;
    std::vector<bool> seats;

public:
    Showtime(std::string time, std::vector<bool> seats);
    
    std::string getTime() const;
    std::vector<bool>& getSeats();
};

#endif