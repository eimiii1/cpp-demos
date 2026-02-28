#include <iostream>
#include <windows.h>
using namespace std;


int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Unchecked: \033[31m■\033[0m\n";
}