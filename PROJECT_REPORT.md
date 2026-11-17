# ACADEMIC PROJECT REPORT

## SCIENTIFIC CALCULATOR APPLICATION IN C++

**Course:** Second Year B.Tech Computer Science and Engineering  
**Project Type:** Object-Oriented Software Engineering (C++)  
**Academic Year:** 2026-2027  

**Submitted By:**
* **Valurouth Tarakesh** (Roll No: `2501020034`)
* **Kumawat Akshat Sujaram** (Roll No: `2501020035`)

---

## Table of Contents
1. [Introduction](#1-introduction)
2. [Objectives](#2-objectives)
3. [System Requirements](#3-system-requirements)
4. [Software Design & Architecture](#4-software-design--architecture)
5. [Implementation Details](#5-implementation-details)
6. [Testing & Verification](#6-testing--verification)
7. [Results & Discussion](#7-results--discussion)
8. [Conclusion & Future Enhancements](#8-conclusion--future-enhancements)

---

## 1. Introduction

The **Scientific Calculator Application in C++** is a console-based computational program developed to perform both foundational arithmetic and advanced scientific mathematical calculations. In academic, engineering, and scientific fields, calculators must not only compute accurate numbers but also strictly validate operands, reject undefined mathematical states, and recover gracefully from erroneous user inputs.

This project demonstrates practical mastery of core Object-Oriented Programming (OOP) concepts in C++, including:
* **Classes and Objects**
* **Encapsulation & Data Hiding**
* **Object Composition (Composition over Inheritance)**
* **Separation of Concerns (Single Responsibility Principle)**
* **Robust Stream Extraction & Error Recovery**

---

## 2. Objectives

The primary objectives of the application are:
1. **Interactive Console User Interface:** Provide a clear, persistent menu-driven interface enabling continuous computations until the user deliberately exits.
2. **Computational Accuracy:** Utilize 64-bit double-precision IEEE-754 floating-point representations for all numerical processing.
3. **Decoupled Architecture:** Separate mathematical calculations from user interface presentation and input parsing.
4. **Defensive Validation:** Prevent program termination or infinite loops caused by non-numeric inputs (e.g., typing text instead of digits).
5. **Mathematical Integrity:** Strictly trap undefined operations such as division by zero, square root of negative numbers, logarithms of non-positive numbers, indeterminate powers ($0^0$, $0^{-k}$), and tangent singularities ($90^\circ + 180^\circ \times k$).

---

## 3. System Requirements

### 3.1 Functional Requirements
* **Arithmetic Operations:** Addition ($a+b$), Subtraction ($a-b$), Multiplication ($a \times b$), and Division ($a/b$ with non-zero check).
* **Scientific Operations:**
  * Square ($x^2$)
  * Square Root ($\sqrt{x}$ with $x \ge 0$)
  * Power ($b^e$ with comprehensive domain verification)
  * Percentage ($\frac{\text{percent} \times \text{value}}{100}$)
* **Trigonometric Functions (Degrees):**
  * Sine ($\sin\theta$)
  * Cosine ($\cos\theta$)
  * Tangent ($\tan\theta$ with asymptotic boundary rejection)
* **Logarithmic Functions:**
  * Common Logarithm ($\log_{10}x$ with $x > 0$)
  * Natural Logarithm ($\ln x$ with $x > 0$)
* **Control Operations:**
  * Option 0 exits the program loop gracefully.
  * Loop continuously re-displays the menu after each calculation.

### 3.2 Non-Functional Requirements
* **Language Standard:** C++17 or higher.
* **Portability:** Compatible with standard compilers including GCC (`g++`), Clang (`clang++`), and Microsoft Visual C++ (`cl.exe`).
* **Fault Tolerance:** Robust against buffer overflow, stream corruption (`cin.fail()`), and invalid inputs.

---

## 4. Software Design & Architecture

### 4.1 Class Hierarchy and Decomposition
The system comprises three primary classes:

1. **`CalculatorApp`**:
   * Coordinates high-level application flow.
   * Encapsulates `ScientificCalculator` and `InputValidator` instances.
   * Manages the menu display, switches on user choices, prompts operands, and formats output.
2. **`ScientificCalculator`**:
   * Encapsulates pure mathematical routines.
   * Strictly decoupled from standard input/output streams.
   * Functions accept `double` and return `double`.
3. **`InputValidator`**:
   * Encapsulates stream cleansing and validation predicates.
   * Discards corrupt input, clears fail states, and checks mathematical constraints.

### 4.2 Class Relationship Diagram

```
+-------------------------------------------------------------+
|                        CalculatorApp                        |
|-------------------------------------------------------------|
| - calculator : ScientificCalculator                         |
| - validator  : InputValidator                               |
|-------------------------------------------------------------|
| + run() : void                                              |
| + displayMenu() : void                                      |
| + performOperation(choice : int) : void                     |
| + displayResult(result : double) : void                     |
+-------------------------------------------------------------+
               |                               |
  contains and |                  contains and |
      uses     |                      uses     |
               v                               v
+-------------------------------+   +-------------------------------+
|     ScientificCalculator      |   |        InputValidator         |
|-------------------------------|   |-------------------------------|
| + add(a, b) : double          |   | + readNumber() : double       |
| + subtract(a, b) : double     |   | + readMenuChoice() : int      |
| + multiply(a, b) : double     |   | + isNonZero(x) : bool         |
| + divide(a, b) : double       |   | + isNonNegative(x) : bool     |
| + square(x) : double          |   | + isPositive(x) : bool        |
| + squareRoot(x) : double      |   | + isValidPower(b, e) : bool   |
| + power(b, e) : double        |   | + isValidTangent(d) : bool    |
| + percentage(p, v) : double   |   +-------------------------------+
| + sine(deg) : double          |
| + cosine(deg) : double        |
| + tangent(deg) : double       |
| + commonLog(x) : double       |
| + naturalLog(x) : double      |
+-------------------------------+
```

---

## 5. Implementation Details

### 5.1 Stream Corruption Recovery
When non-numeric input is supplied to `cin >> value`, the stream fails, setting `std::ios_base::failbit`. Without proper handling, future read attempts immediately fail, triggering infinite execution loops. The implementation resolves this defensively:

```cpp
double InputValidator::readNumber() const {
    double value;
    while (true) {
        if (std::cin >> value) {
            if (std::isfinite(value)) {
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
```

### 5.2 Power Function Boundaries
The power operation $b^e$ incorporates three boundary checks:
* $0^0$: Indeterminate form; rejected.
* $0^{-k}$: Equivalent to $\frac{1}{0^k}$, which constitutes division by zero; rejected.
* Negative base with non-integer exponent ($(-4)^{0.5}$): Yields imaginary/complex numbers; rejected in real arithmetic.

### 5.3 Tangent Asymptotic Singularities
$\tan(\theta)$ approaches $\pm\infty$ at odd multiples of $90^\circ$. Due to finite floating-point approximation of $\pi$, $\cos(90^\circ)$ evaluates to approximately $6.12 \times 10^{-17}$ rather than true zero, yielding artificial values on the order of $10^{16}$. The validator enforces an epsilon threshold:
```cpp
bool InputValidator::isValidTangent(double degrees) const {
    constexpr double PI = 3.14159265358979323846;
    double radians = degrees * (PI / 180.0);
    return std::fabs(std::cos(radians)) > 1e-12;
}
```

---

## 6. Testing & Verification

A test suite comprising 30 verification cases was designed and executed.

### Summary of Test Results
* **Basic Arithmetic:** All operations (addition, subtraction, multiplication, division) executed accurately across integer and floating-point inputs.
* **Zero Denominator:** Division by zero successfully trapped with message `"Cannot divide by zero."`
* **Roots & Powers:** Negative square roots and unsupported powers ($0^0$, $0^{-2}$, $(-4)^{0.5}$) were intercepted.
* **Trigonometry:** Evaluated correctly; asymptotic angles ($90^\circ$, $270^\circ$) rejected.
* **Logarithms:** Common and natural logarithms evaluated correctly; non-positive inputs rejected with message `"Require a positive number."`
* **Malformed Input:** Characters such as `"abc"` or out-of-range choices were discarded and prompted again cleanly.

Refer to `test_cases.md` for the line-by-line verification table.

---

## 7. Results & Discussion

The modular design achieved complete separation between presentation and computation:
1. **Maintainability:** Modifying mathematical routines does not impact user input logic or menu formatting.
2. **Reusability:** `ScientificCalculator` and `InputValidator` can be linked directly into GUI or web-assembly wrappers without rewriting code.
3. **Reliability:** Defensive stream extraction eliminates common CLI crash vectors.

---

## 8. Conclusion & Future Enhancements

The **Scientific Calculator Application in C++** fulfills all technical and academic requirements set forth for the Second Year B.Tech CSE Project:
* Implemented complete 13-operation scientific functionality.
* Encapsulated logic across modular classes.
* Enforced mathematical edge case handling.
* Provided full documentation and test coverage.

### Potential Future Enhancements:
1. Memory operations (M+, M-, MR, MC).
2. Expression parsing (Reverse Polish Notation or Shunting-yard algorithm for parenthesized strings).
3. Graphical User Interface (GUI) using Qt or wxWidgets.
