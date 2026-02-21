@echo off
REM Build Script for 01_Calculator

REM Create build folder if it doesn't exist
if not exist build (
    mkdir build
)

REM Compile all cpp files
g++ src\main.cpp src\basic_operation.cpp src\advanced_operation.cpp -Iinclude -o build\calculator.exe

REM Check if compilation succeeded
if %ERRORLEVEL% == 0 (
    echo Compilation successful!
    echo Runinng program...
    build\calculator.exe
) else (
    echo Compilation failed!
)

echo.
pause