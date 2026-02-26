# Student Management System

A *Console-Based* **Student Management System** that primarily uses under Classes & Objects and `bool` *CRUD* Functions.

This repository documents creation, updating, deletion, listing, and searching of students records in a simple console environment. It highlights core object-oriented programming concepts in C++, including:

- **Encapsulation**: Each student's data is managed through getters and setters.
- **Object Collections**: Students are stored as `objects` and managed in a `std::vector`.
- **Boolean Return Functions**: CRUD operations return `true` or `false` to indicate success or failure, allowing clear feedback in the console.
- **User-Friendly Menu Handling**: Input is properly validated and managed using `std::cin.ignore` and `std::getline` to handle edge cases.

## Features 
- Add a new student with their *name, age, and grade*.
- Update an existing student's grade.
- Delete an existing student's data.
- List each student's information.
- Search for a student by name.

### Requirements
- C++17 compatible compiler (GCC, Clang, or MSVC).
- Terminal/Console for running the program.

#### How to Run
1. Clone the repository or download the source file.
2. Open terminal and navigate to the folder containing the file.
3. Compile the program.
```bash
g++ src\main.cpp src\Student.cpp -Iinclude -o build\student_manager.exe
```

Or, if you want an automated way, you can use a **batch file**.
```bat
@echo off
REM Build Script for "Student Management System"

REM Create build folder if not exist
if not exist build (
	mkdir build
)

REM Compile all cpp files
g++ src\main.cpp src\Student.cpp -Iinclude -o build\student_manager.exe

REM Check if compilation succeeded
if %ERRORLEVEL% == 0 (
	echo Compilation successful!
	echo Running Program...
	build\student_manager.exe
) else (
	echo Compilation failed!
)

echo.
pause
```