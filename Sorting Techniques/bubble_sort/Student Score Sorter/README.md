# 🎓 Student Score Sorter (C++)

A simple C++ console application that alows users to input student scores and sort them in both ascending and descending order using the Bubble Sort algorithm.

## 📌 Features

- ✅ Displays scores in ascending order
- ✅ Displays scores in descending order
- ✅ Implements manual Bubble Sort (no STL sort used)
- ✅ Simple interactive console interface

## 🧠 Concepts Used

- `std::vector`
- Functions
- Pass-by-reference
- Nested loops
- Bubble Sort algorithm
- Basic input validation

## 💻 Example Run

```
Student Score Sorter

Score: 85

0 - Repeat
1 - Result
Entry: 0

Score: 72

0 - Repeat 
1 - Result 
Entry: 0

Score: 90

0 - Repeat
1 - Result
Entry: 1

Ascending: 72 85 90
Descending: 90 85 72
```

## 📂 Functions Overview

`ascending(vector<int>& scores)`
Sorts the scores in ascending order using Bubble Sort.

`descending(vector<int>& scores)`
Sorts the scores in descending order using Bubble Sort.

`display(vector<int>& scores)`
Calls both sorting functions and prints the results.

## 🚀 How to Compile & Run

#### Using g++

```bash
g++ main.cpp -o sorter
./sorter
```

#### Using MSYS2 / MinGW (Windows)

```bash
g++ main.cpp -o sorter.exe
sorter.exe
```

## ⚠️ Note

Since both sorting functions modify the same vector by reference, the vector is re-sorted when switching between ascending and descending. This works correctly for display purposes but could be improved by copying the vector before sorting.

## 🔮 Possible Improvements

- Add input validation for non-integer values
- Use `std::sort` for comparison
- Add menu system
- Prevent duplicate sorting logic (use a flag for order type)
- Add average, highest, and lowest score calculations
- Add file saving functionality

## 📚 Learning Purpose

- Algorithm implementation
- Vector manipulation
- Function structuring in C++