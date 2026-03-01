# 🎟️ Movie Ticket Booking System (C++)

A **console-based movie ticket booking system** built in C++ using object-oriented programming principles.

This system allows users to:

- View available movies
- Select a movie
- Choose a showtime
- Reserve a seat
- Confirm their booking


## 🧠 Concepts Demonstrated

- Classes & Objects
- Encapsulation
- Composition
- References & Pointers
- `std::vector`
- Input handling
- Basic console UI formatting


## 📂 Project Structure
Classes & Objects/  
└── Movie Ticket Booking/  
├── include/  
│ ├── Cinema.h  
│ ├── Movie.h  
│ ├── Showtime.h  
│ └── Ticket.h  
├── src/  
│ ├── main.cpp  
│ ├── Cinema.cpp  
│ ├── Movie.cpp  
│ └── Showtime.cpp  
└── README.md

---

## 🏗️ System Architecture

### 🎬 Movie
- Stores:
  - Title
  - Duration
  - Rating
  - List of showtimes
- Displays movie information and seat layout

### ⏰ Showtime
- Stores:
  - Time
  - Seat availability (`std::vector<bool>`)
- Tracks which seats are taken or available

### 🎫 Cinema
- Manages all movies
- Handles:
  - Movie selection
  - Showtime selection
  - Seat reservation
  - Booking confirmation

---

## 🎮 Features

### 1️⃣ List Movies
Displays formatted movie table with:
- Title
- Duration
- Rating (color-coded)

Example:
##### Title Duration Rating
The Loved One 1h 40m R-13  
Until She Remembers 1h 47m PG  
Scream 7 1h 54m R-16

### 2️⃣ Seat Layout Display  
  
Seats are shown using: 
☐ → Available  
☑ → Taken

Displayed in rows of 5 seats.

---

### 3️⃣ Booking Flow

1. Select Movie
2. Select Showtime
3. Select Seat
4. Confirm Booking
5. Seat becomes permanently reserved

---

## 🛠️ How to Build & Run

### Requirements
- C++17 compatible compiler
  - g++
  - clang++

---

### Compile

From project root:

```bash
g++ src\main.cpp src\models\Cinema.cpp src\models\Movie.cpp src\models\Showtime.cpp src\models\Ticket.cpp -Iinclude -o build\cinema.exe
```

### Run
- Inside build/ folder
```bash
./cinema.exe
```

---
## 🔧 Possible Improvements

- Multiple seat booking
- Input validation loop
- Ticket pricing system
- Save bookings to file
- Cancel booking feature
- GUI version (Qt / React / SFML)

---
## 👨‍💻 Author

**eimiii1**

GitHub Repository:  
[https://github.com/eimiii1/structured-cpp](https://github.com/eimiii1/structured-cpp)

## 📌 Purpose

This project was built as a structured C++ practice project to strengthen understanding of:

- Object relationships
    
- State mutation using references
    
- Real-world class modeling
    
- Console-based application design