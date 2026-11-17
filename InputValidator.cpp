#include "InputValidator.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <string>

double InputValidator::readNumber() const {
    double value;
    while (true) {
        if (std::cin >> value) {
            if (std::isfinite(value)) {
                // Clear any remaining characters on the line
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            } else {
                std::cout << "Invalid input: Non-finite number detected. Please enter a valid number: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } else {
            std::cout << "Invalid input: Non-numeric entry detected. Please enter a valid number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int InputValidator::readMenuChoice() const {
    int choice;
    while (true) {
        if (std::cin >> choice) {
            if (choice >= 0 && choice <= 13) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return choice;
            } else {
                std::cout << "Invalid choice. Please enter a valid option between 0 and 13: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } else {
            std::cout << "Invalid choice: Non-integer entry detected. Please enter an option (0-13): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

bool InputValidator::isNonZero(double x) const {
    return std::fabs(x) > 1e-15;
}

bool InputValidator::isNonNegative(double x) const {
    return x >= 0.0;
}

bool InputValidator::isPositive(double x) const {
    return x > 0.0;
}

bool InputValidator::isValidPower(double base, double exponent) const {
    // 0 raised to 0 is indeterminate and explicitly rejected
    if (base == 0.0 && exponent == 0.0) {
        return false;
    }
    // 0 raised to negative power is division by zero
    if (base == 0.0 && exponent < 0.0) {
        return false;
    }
    // Negative base with non-integer exponent produces complex numbers
    if (base < 0.0 && std::floor(exponent) != exponent) {
        return false;
    }
    return true;
}

bool InputValidator::isValidTangent(double degrees) const {
    // Tangent is undefined at odd multiples of 90 degrees (cos(theta) == 0)
    constexpr double PI = 3.14159265358979323846;
    double radians = degrees * (PI / 180.0);
    return std::fabs(std::cos(radians)) > 1e-12;
}
