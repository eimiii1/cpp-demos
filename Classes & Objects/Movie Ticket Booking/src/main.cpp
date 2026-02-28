#include <iostream>
#include <limits>
#include "../include/Cinema.h"
#define NOMINMAX

// #include <windows.h> for UTF-8
#ifdef _WIN32

#include <windows.h>

#endif

void menu();
void inputMenu(int& choice);
void handleChoice(Cinema& cinema, int& choice);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Cinema cinema;
    std::cout << "\n\033[31mROBINSONS\033[0m MOVIEWO\033[31mR\033[0mLD\n";
    int choice;

    while (choice != 3) {
        menu();
        inputMenu(choice);
        handleChoice(cinema, choice);
    }
}

void menu() {
    std::vector<std::string> menu = {
        "View Movies",
        "Book Ticket",
        "Close"
    };

    std::cout << "\nMENU\n" << std::endl;
    for (int i = 0; i < menu.size(); i++) {
        std::cout << i+1 << ". " << menu[i] << "\n";
    }
}

void inputMenu(int& choice) {
    std::cout << "\nSelect option: ";
    std::cin >> choice;

    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void handleChoice(Cinema& cinema, int& choice) {
    switch (choice) {
        case 1: cinema.listMovies(); break;
        case 2: cinema.handleBooking(cinema); break;
    }
}