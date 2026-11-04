#include "ScientificCalculator.h"
#include <cmath>

double ScientificCalculator::add(double a, double b) const {
    return a + b;
}

double ScientificCalculator::subtract(double a, double b) const {
    return a - b;
}

double ScientificCalculator::multiply(double a, double b) const {
    return a * b;
}

double ScientificCalculator::divide(double a, double b) const {
    return a / b;
}

double ScientificCalculator::square(double x) const {
    return x * x;
}

double ScientificCalculator::squareRoot(double x) const {
    return std::sqrt(x);
}

double ScientificCalculator::power(double base, double exponent) const {
    return std::pow(base, exponent);
}

double ScientificCalculator::percentage(double percent, double value) const {
    return (percent * value) / 100.0;
}

double ScientificCalculator::sine(double degrees) const {
    double radians = degrees * (PI / 180.0);
    double result = std::sin(radians);
    if (std::fabs(result) < 1e-12) {
        return 0.0;
    }
    return result;
}

double ScientificCalculator::cosine(double degrees) const {
    double radians = degrees * (PI / 180.0);
    double result = std::cos(radians);
    if (std::fabs(result) < 1e-12) {
        return 0.0;
    }
    return result;
}

double ScientificCalculator::tangent(double degrees) const {
    double radians = degrees * (PI / 180.0);
    double result = std::tan(radians);
    if (std::fabs(result) < 1e-12) {
        return 0.0;
    }
    return result;
}

double ScientificCalculator::commonLog(double x) const {
    return std::log10(x);
}

double ScientificCalculator::naturalLog(double x) const {
    return std::log(x);
}
