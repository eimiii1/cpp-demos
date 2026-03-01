#ifndef TICKET_H
#define TICKET_H

class Ticket {
private:
    std::string movie;
    std::string showtime;
    std::string seat;
    
public:
    Ticket(std::string movie, std::string showtime, std::string seat);

    void showTicket();
};

#endif