#ifndef CALCULATOR_APP_H
#define CALCULATOR_APP_H

#include "ScientificCalculator.h"
#include "InputValidator.h"

/**
 * @file CalculatorApp.h
 * @brief Application controller managing the menu loop, input dispatch, and output presentation.
 *
 * Project Done By:
 * - Valurouth Tarakesh (2501020034)
 * - Kumawat Akshat Sujaram (2501020035)
 *
 * Responsibilities:
 * - Render clear, user-friendly console menus.
 * - Manage user workflow and operand inputs.
 * - Coordinate between InputValidator and ScientificCalculator.
 * - Format and present results while catching range or overflow errors.
 */

class CalculatorApp {
private:
    ScientificCalculator calculator;
    InputValidator validator;

public:
    CalculatorApp() = default;

    void run();
    void displayMenu() const;
    void performOperation(int choice);
    void displayResult(double result) const;
};

#endif // CALCULATOR_APP_H
