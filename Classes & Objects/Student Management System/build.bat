@echo off
REM Build Script for "Student Management System"

REM Create build folder if not exist
if not exist build (
    mkdir build
)

REM Compile all cpp files
g++ src\main.cpp src\Student.cpp -Iinclude -o build\manager.exe

REM Check if compilation succeeded
if %ERRORLEVEL% == 0 (
    echo Compilation successful!
    echo Running Program...
    build\manager.exe
) else (
    echo Compilation failed!
)

echo. 
pause