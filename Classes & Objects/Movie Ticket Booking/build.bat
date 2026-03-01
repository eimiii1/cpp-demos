@echo off
REM Build Script for "Movie Ticket Booking"

if not exist build (
    mkdir build
)

g++ src\main.cpp src\models\Movie.cpp src\models\Cinema.cpp src\models\Showtime.cpp -Iinclude -o build\main.exe 

if %ERRORLEVEL% == 0 (
    echo Compilation Successful!
    echo Running Program...
    build\main.exe
)

echo. 
pause