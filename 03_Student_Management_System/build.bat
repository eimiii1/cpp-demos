@echo off

if not exist build (
    mkdir build
)

REM compile all files
g++ src\main.cpp -Iinclude -o build/main.exe

if %ERRORLEVEL% == 0 (
    echo Program running successful!
    build\main.exe
)

echo. 
pause