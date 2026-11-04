#ifndef SCIENTIFIC_CALCULATOR_H
#define SCIENTIFIC_CALCULATOR_H

/**
 * @file ScientificCalculator.h
 * @brief Mathematical calculation engine for the Scientific Calculator Application.
 *
 * Project Done By:
 * - Valurouth Tarakesh (2501020034)
 * - Kumawat Akshat Sujaram (2501020035)
 *
 * Responsibilities:
 * - Pure mathematical evaluation of arithmetic, scientific, trigonometric, and logarithmic functions.
 * - Stateless calculations accepting double operands and returning double results.
 * - Strictly decoupled from stream I/O (no std::cin or std::cout).
 */

class ScientificCalculator {
public:
    // Basic Arithmetic Operations
    double add(double a, double b) const;
    double subtract(double a, double b) const;
    double multiply(double a, double b) const;
    double divide(double a, double b) const;

    // Scientific Operations
    double square(double x) const;
    double squareRoot(double x) const;
    double power(double base, double exponent) const;
    double percentage(double percent, double value) const;

    // Trigonometric Operations (input in degrees)
    double sine(double degrees) const;
    double cosine(double degrees) const;
    double tangent(double degrees) const;

    // Logarithmic Operations
    double commonLog(double x) const;
    double naturalLog(double x) const;

    // Mathematical Constants
    static constexpr double PI = 3.14159265358979323846;
};

#endif // SCIENTIFIC_CALCULATOR_H
