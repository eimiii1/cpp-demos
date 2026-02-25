#pragma once
#include <iostream>
#include <cmath>

class Calculator {
public:
    // Basic Operations
    double add(double a, double b) {return a + b;}
    double subtract(double a, double b) {return a - b;}
    double multiply(double a, double b) {return a * b;}
    double divide(double a, double b) {
        if (b == 0) {
            std::cerr << "Error: Division by zero!\n";  
            return NAN;
        }
        return a / b;
    }
    
    // Advanced Operations
    double power(double base, double exp) {return std::pow(base, exp); }
    double squareRoot(double x) {return std::sqrt(x); }
    double factorial(int n) {
        if (n < 0) return NAN;
        double result = 1;
        for (int i = 2; i <= n; ++i) result *= i;
        return result;
    }
    
    double sine(double x) {return std::sin(x);}
    double cosine(double x) {return std::cos(x);}
    double tangent(double x) {return std::tan(x);}
    double logN(double x) {return std::log(x);}
    double log10N(double x) { return std::log10(x);}
};