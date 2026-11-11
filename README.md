# Scientific Calculator Application in C++

A robust, menu-driven scientific calculator application implemented in C++ demonstrating object-oriented programming, clean multi-file separation, composition, and defensive stream validation.

---

## Academic Project Details
* **Course:** Second Year B.Tech Computer Science and Engineering (CSE)
* **Project Type:** Core C++ Object-Oriented Software Engineering Project
* **Authors:**
  * **Valurouth Tarakesh** (Roll No: `2501020034`)
  * **Kumawat Akshat Sujaram** (Roll No: `2501020035`)

---

## Features

### 1. Basic Arithmetic
* **Addition (`+`)**: Computes $a + b$
* **Subtraction (`-`)**: Computes $a - b$
* **Multiplication (`*`)**: Computes $a \times b$
* **Division (`/`)**: Computes $a / b$ with strict division-by-zero validation

### 2. Scientific Operations
* **Square ($x^2$)**: Real-number squaring
* **Square Root ($\sqrt{x}$)**: Non-negative validation ($x \ge 0$)
* **Power ($b^e$)**: Real exponentiation with strict domain checks:
  * Rejects indeterminate form $0^0$
  * Rejects zero to negative exponents ($0^{-k}$)
  * Rejects negative bases with fractional exponents ($(-b)^{0.5}$)
* **Percentage**: $\frac{\text{percent} \times \text{value}}{100}$

### 3. Trigonometric Functions (Degree Mode)
* **Sine ($\sin$)**: Evaluates angle in degrees, converts to radians internally
* **Cosine ($\cos$)**: Evaluates angle in degrees, converts to radians internally
* **Tangent ($\tan$)**: Rejects vertical asymptotes ($90^\circ + 180^\circ \times k$) using cosine tolerance

### 4. Logarithmic Functions
* **Common Logarithm ($\log_{10}$)**: Strictly enforces positive domain ($x > 0$)
* **Natural Logarithm ($\ln$, base $e$)**: Strictly enforces positive domain ($x > 0$)

### 5. Defensive Input Validation & Error Handling
* Recovers from non-numeric garbage input without crashing or infinite loops.
* Discards invalid menu choices and prompts again.
* Prevents IEEE-754 overflow/underflow or NaN propagation using `std::isfinite()`.

---

## Architecture & Class Design

The application follows the **Single Responsibility Principle (SRP)** and object **Composition**:

```
CalculatorApp (Coordinator)
  ├── ScientificCalculator (Pure Math Engine)
  └── InputValidator (Stream Sanitation & Domain Predicates)
```

| Class | Responsibilities | Key Functions |
| :--- | :--- | :--- |
| **`CalculatorApp`** | Coordinates the menu loop, input workflow, calculation dispatch, and result display. | `run()`, `displayMenu()`, `performOperation()`, `displayResult()` |
| **`ScientificCalculator`** | Stateless mathematical calculation methods. Never interacts with `std::cin` or `std::cout`. | `add()`, `subtract()`, `multiply()`, `divide()`, `square()`, `squareRoot()`, `power()`, `percentage()`, `sine()`, `cosine()`, `tangent()`, `commonLog()`, `naturalLog()` |
| **`InputValidator`** | Parses numbers, clears corrupt stream flags, discards invalid input, and validates domains. | `readNumber()`, `readMenuChoice()`, `isNonZero()`, `isNonNegative()`, `isPositive()`, `isValidPower()`, `isValidTangent()` |

---

## File Structure

```
Scientific Calculator/
├── main.cpp                  # Program entry point
├── CalculatorApp.h           # Application controller declaration
├── CalculatorApp.cpp         # Application controller implementation
├── ScientificCalculator.h    # Mathematical engine declaration
├── ScientificCalculator.cpp  # Mathematical engine implementation
├── InputValidator.h          # Input validator declaration
├── InputValidator.cpp        # Input validator implementation
├── CMakeLists.txt            # CMake build configuration
├── Makefile                  # GNU Make build configuration
├── build.bat                 # One-click Windows build script
├── test_cases.md             # Detailed test matrix and execution results
├── PROJECT_REPORT.md         # Comprehensive academic documentation
└── README.md                 # Project documentation and usage guide
```

---

## Compilation & Execution

### Option 1: Direct g++ / MinGW / Clang
```bash
g++ -std=c++17 main.cpp CalculatorApp.cpp ScientificCalculator.cpp InputValidator.cpp -o ScientificCalculator
./ScientificCalculator
```

### Option 2: Windows Build Script
Double-click `build.bat` or run in terminal:
```cmd
build.bat
ScientificCalculator.exe
```

### Option 3: CMake
```bash
mkdir build
cd build
cmake ..
cmake --build .
./ScientificCalculator
```

### Option 4: Make
```bash
make
./ScientificCalculator
```

---

## Example Usage Session

```text
======================================================
             SCIENTIFIC CALCULATOR (C++)              
======================================================
  1 Addition            2 Subtraction       3 Multiplication
  4 Division            5 Square            6 Square Root
  7 Power               8 Percentage        9 Sine
 10 Cosine             11 Tangent          12 Common Log
 13 Natural Log         0 Exit
======================================================
Enter choice: 7

[Power]
Enter base: 2
Enter exponent: 3
Result: 8

======================================================
             SCIENTIFIC CALCULATOR (C++)              
======================================================
Enter choice: 4

[Division]
Enter dividend (numerator): 15
Enter divisor (denominator): 0
Cannot divide by zero.

======================================================
             SCIENTIFIC CALCULATOR (C++)              
======================================================
Enter choice: 0

Exiting application. Thank you for using Scientific Calculator!
```

---

## Authors & Acknowledgments
* **Valurouth Tarakesh** (2501020034)
* **Kumawat Akshat Sujaram** (2501020035)  
Second Year B.Tech Computer Science and Engineering.
