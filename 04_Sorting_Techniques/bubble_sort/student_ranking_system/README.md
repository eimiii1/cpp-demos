# 🎓 Student Ranking System (C++)

![C++](https://img.shields.io/badge/Language-C++-blue) 
![Status](https://img.shields.io/badge/Status-Completed-brightgreen) 
![License](https://img.shields.io/badge/License-MIT-lightgrey) 

A simple **menu-driven C++ console application** to manage student scores and display rankings in **descending order** using **Bubble Sort**.  

This project demonstrates **structs, vectors, function usage, and basic sorting algorithms** in C++.

---

## 📌 Features

- ✅ Add multiple students with **name** and **score**  
- ✅ Automatically sorts students by **score in descending order**  
- ✅ Displays a **ranking list**  
- ✅ Simple **interactive menu** interface  
- ✅ Uses **Bubble Sort** implemented manually (no STL sort)

---

## 🧠 Concepts Covered

- `struct` as a custom datatype  
- `vector` for dynamic arrays of objects  
- Passing **by reference** to modify function parameters  
- Nested loops for **Bubble Sort**  
- Console input/output (`cin`, `getline`, `cout`)  
- Function decomposition for modularity  

---

## 💻 How to Use

### Example Run
```
Student Ranking System

1. Add Student
2. Display Ranking 
3. Exit 
   
Choose option: 1

Student name: Philip
Score: 92

Student Added.

1. Add Student
2. Display Ranking
3. Exit 
   
Choose option: 1

Student name: Jeanclaude
Score: 95

Student Added.

1. Add Student
2. Display Ranking
3. Exit 
   
Choose option: 1

Student name: Nig
Score: 72

Student Added.

1. Add Student
2. Display Ranking
3. Exit 
   
Choose option: 2

Rankings

1. Jeanclaude - 95
2. Philip - 92
3. Nig - 72
---
1. Add Student
2. Display Ranking
3. Exit 
   
Choose option: 3

System exit.
```


---

## 🛠️ How to Compile

### Using g++

```bash
g++ main.cpp -o ranking
./ranking
```

### Using MSYS2 / MinGW (Windows)

```bash
g++ main.cpp -o ranking.exe
ranking.exe
```


---
## 🔮 Possible Improvements

- Allow user to choose **ascending or descending order**
- Search for a student by name
- Display top N students
- Add **average, highest, and lowest score calculations**
- Save and load rankings from a file

---
## 📚 Learning Purpose

This project is ideal for beginners practicing:

- Basic data structures (`struct`, `vector`)
- Manual sorting algorithms
- Function decomposition and modularity
- Console I/O handling