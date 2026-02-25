@echo off 
REM Build Script for 02_Bank_System

REM Create build folder if it doesn't exist
if not exist build (
    mkdir build
)

REM Compile all cpp files
g++ src\main.cpp src\models\account.cpp src\models\bank.cpp -Iinclude -o build\main.exe

REM Check if compilation succeeded
if %ERRORLEVEL% == 0 (
    echo Compilation successful!
    echo Running program...
    build\main.exe
) else (
    echo Compilation failed!
)

echo.
pause