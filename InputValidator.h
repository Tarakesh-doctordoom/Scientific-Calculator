#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

/**
 * @file InputValidator.h
 * @brief Input validation and mathematical domain verification helper.
 *
 * Project Done By:
 * - Valurouth Tarakesh (2501020034)
 * - Kumawat Akshat Sujaram (2501020035)
 *
 * Responsibilities:
 * - Clean stream extraction, discarding non-numeric garbage input without crashing.
 * - Reprompting on invalid menu choices or invalid operand entries.
 * - Enforcing mathematical preconditions before operations are invoked.
 */

class InputValidator {
public:
    // Stream Parsing Methods
    double readNumber() const;
    int readMenuChoice() const;

    // Mathematical Condition Predicates
    bool isNonZero(double x) const;
    bool isNonNegative(double x) const;
    bool isPositive(double x) const;
    bool isValidPower(double base, double exponent) const;
    bool isValidTangent(double degrees) const;
};

#endif // INPUT_VALIDATOR_H
