#include "CalculatorApp.h"
#include <iostream>
#include <iomanip>
#include <cmath>

void CalculatorApp::displayMenu() const {
    std::cout << "\n======================================================\n";
    std::cout << "             SCIENTIFIC CALCULATOR (C++)              \n";
    std::cout << "======================================================\n";
    std::cout << "  1 Addition            2 Subtraction       3 Multiplication\n";
    std::cout << "  4 Division            5 Square            6 Square Root\n";
    std::cout << "  7 Power               8 Percentage        9 Sine\n";
    std::cout << " 10 Cosine             11 Tangent          12 Common Log\n";
    std::cout << " 13 Natural Log         0 Exit\n";
    std::cout << "======================================================\n";
    std::cout << "Enter choice: ";
}

void CalculatorApp::run() {
    int choice = -1;
    while (choice != 0) {
        displayMenu();
        choice = validator.readMenuChoice();
        if (choice == 0) {
            std::cout << "\nExiting application. Thank you for using Scientific Calculator!\n";
            break;
        }
        performOperation(choice);
    }
}

void CalculatorApp::performOperation(int choice) {
    switch (choice) {
        case 1: { // Addition
            std::cout << "\n[Addition]\nEnter first operand: ";
            double a = validator.readNumber();
            std::cout << "Enter second operand: ";
            double b = validator.readNumber();
            displayResult(calculator.add(a, b));
            break;
        }
        case 2: { // Subtraction
            std::cout << "\n[Subtraction]\nEnter first operand: ";
            double a = validator.readNumber();
            std::cout << "Enter second operand: ";
            double b = validator.readNumber();
            displayResult(calculator.subtract(a, b));
            break;
        }
        case 3: { // Multiplication
            std::cout << "\n[Multiplication]\nEnter first operand: ";
            double a = validator.readNumber();
            std::cout << "Enter second operand: ";
            double b = validator.readNumber();
            displayResult(calculator.multiply(a, b));
            break;
        }
        case 4: { // Division
            std::cout << "\n[Division]\nEnter dividend (numerator): ";
            double a = validator.readNumber();
            std::cout << "Enter divisor (denominator): ";
            double b = validator.readNumber();
            if (!validator.isNonZero(b)) {
                std::cout << "Cannot divide by zero.\n";
                return;
            }
            displayResult(calculator.divide(a, b));
            break;
        }
        case 5: { // Square
            std::cout << "\n[Square]\nEnter operand: ";
            double x = validator.readNumber();
            displayResult(calculator.square(x));
            break;
        }
        case 6: { // Square Root
            std::cout << "\n[Square Root]\nEnter operand: ";
            double x = validator.readNumber();
            if (!validator.isNonNegative(x)) {
                std::cout << "Require a non-negative number.\n";
                return;
            }
            displayResult(calculator.squareRoot(x));
            break;
        }
        case 7: { // Power
            std::cout << "\n[Power]\nEnter base: ";
            double base = validator.readNumber();
            std::cout << "Enter exponent: ";
            double exponent = validator.readNumber();
            if (!validator.isValidPower(base, exponent)) {
                std::cout << "Unsupported powers: negative base with non-integer exponent, zero to a negative power, and 0 raised to 0 are rejected.\n";
                return;
            }
            displayResult(calculator.power(base, exponent));
            break;
        }
        case 8: { // Percentage
            std::cout << "\n[Percentage]\nEnter percentage (e.g. 20 for 20%): ";
            double percent = validator.readNumber();
            std::cout << "Enter total value: ";
            double value = validator.readNumber();
            displayResult(calculator.percentage(percent, value));
            break;
        }
        case 9: { // Sine
            std::cout << "\n[Sine]\nEnter angle in degrees: ";
            double degrees = validator.readNumber();
            displayResult(calculator.sine(degrees));
            break;
        }
        case 10: { // Cosine
            std::cout << "\n[Cosine]\nEnter angle in degrees: ";
            double degrees = validator.readNumber();
            displayResult(calculator.cosine(degrees));
            break;
        }
        case 11: { // Tangent
            std::cout << "\n[Tangent]\nEnter angle in degrees: ";
            double degrees = validator.readNumber();
            if (!validator.isValidTangent(degrees)) {
                std::cout << "Reject undefined angle; tangent is undefined at 90° + 180° × k.\n";
                return;
            }
            displayResult(calculator.tangent(degrees));
            break;
        }
        case 12: { // Common Log
            std::cout << "\n[Common Logarithm (base 10)]\nEnter operand: ";
            double x = validator.readNumber();
            if (!validator.isPositive(x)) {
                std::cout << "Require a positive number.\n";
                return;
            }
            displayResult(calculator.commonLog(x));
            break;
        }
        case 13: { // Natural Log
            std::cout << "\n[Natural Logarithm (base e)]\nEnter operand: ";
            double x = validator.readNumber();
            if (!validator.isPositive(x)) {
                std::cout << "Require a positive number.\n";
                return;
            }
            displayResult(calculator.naturalLog(x));
            break;
        }
        default:
            std::cout << "Invalid choice.\n";
            break;
    }
}

void CalculatorApp::displayResult(double result) const {
    if (!std::isfinite(result)) {
        std::cout << "Error: Calculation resulted in a non-finite value or numeric range overflow.\n";
        return;
    }
    std::cout << "Result: " << result << "\n";
}
