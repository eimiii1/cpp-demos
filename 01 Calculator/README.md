# 🖩 Advanced CLI Calculator (C++)

![C++](https://img.shields.io/badge/Language-C++-blue)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![License](https://img.shields.io/badge/License-MIT-lightgrey)

A **Command-Line Calculator** implemented in C++ using **classes, objects, and modular header files (`.hpp`)**.  
This project demonstrates **object-oriented programming, modular design, and clean code structure** in C++.

---

## 📌 Features

- ✅ Perform **basic arithmetic operations**: addition, subtraction, multiplication, division  
- ✅ Modular design using **header (`.hpp`) and implementation (`.cpp`) files**  
- ✅ Object-oriented approach with **classes and objects**  
- ✅ Clean CLI interface for easy user interaction  
- ✅ Reusable code for extending with more operations  

---

## 🧠 Concepts Covered

- Classes and objects in C++  
- Modular programming using `.hpp` and `.cpp` files  
- Function declarations and definitions  
- Console input/output (`cin`, `cout`)  

---

## 💻 How to Use

### Example Run

```
Calculator

1. Basic Operations
2. Advanced Operations 
3. Exit
   
Select option: 1

Basic Operations

1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Go Back
   
Select operation: 1

Enter two number (Seperated by spaces): 5 10

Output: 15

Basic Operations

1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Go Back
   
Select operation: 5

Calculator

1. Basic Operations
2. Advanced Operations
3. Exit
   
Select option: 3

System exit.
```

---

## 🛠️ How to Compile

### Using g++
```bash
g++ src\main.cpp src\basic_operation.cpp src\advanced_operation.cpp -Iinclude -o build\calculator
./calculator
```

### Using MSYS2 / MinGW (Windows)
```bash
g++ src\main.cpp src\basic_operation.cpp src\advanced_operation.cpp -Iinclude -o build\calculator.exe
calculator.exe
```