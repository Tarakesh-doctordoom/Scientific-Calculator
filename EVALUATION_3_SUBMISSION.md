# PROJECT EVALUATION 3: DEFENSIVE VALIDATION & MODULAR ARCHITECTURE

**Course:** Second Year B.Tech Computer Science and Engineering  
**Subject:** Object-Oriented Programming in C++ / Project Lab  
**Evaluation Milestone:** Evaluation 3 (Version 3 - Defensive Validation & Full Architecture)  
**Evaluation Date:** 17 / 18 November 2026  
**Marks Weightage:** 4 Marks  
**GitHub Repository:** [https://github.com/Tarakesh-doctordoom/Scientific-Calculator](https://github.com/Tarakesh-doctordoom/Scientific-Calculator)  

---

## Student Information

| Student Name | Roll Number / University ID | Department | Year / Semester |
| :--- | :---: | :---: | :---: |
| **Valurouth Tarakesh** | `2501020034` | Computer Science & Engineering | 2nd Year / Sem III |
| **Kumawat Akshat Sujaram** | `2501020035` | Computer Science & Engineering | 2nd Year / Sem III |

---

## 1. Executive Summary & Evaluation Scope

**Evaluation 3** represents the pinnacle of the engineering implementation, delivering **Version 3.0** of the Scientific Calculator Application. The focal points of this evaluation are **industrial-grade input validation**, **mathematical domain boundary protection**, **stream failure recovery**, and **strict multi-file separation** adhering to the Single Responsibility Principle.

### Objectives Achieved in Evaluation 3:
1. Created dedicated `InputValidator` class to decouple input extraction and boundary checks from presentation and math engines.
2. Implemented stream corruption recovery (`cin.clear()` and `cin.ignore()`) eliminating terminal crashes and infinite loops caused by non-numeric inputs.
3. Implemented rigorous mathematical boundary guards:
   * Division by zero (`isNonZero`)
   * Negative square roots (`isNonNegative`)
   * Logarithms of non-positive numbers (`isPositive`)
   * Indeterminate and complex power expressions (`isValidPower`)
   * Tangent asymptotic singularities with cosine epsilon guard (`isValidTangent`)
4. Implemented floating-point range verification via `std::isfinite(result)` to prevent numeric overflow.
5. Finalized full multi-file modularization (`.h` / `.cpp` separation across all classes).
6. Executed a comprehensive 30-case test matrix (`test_cases.md`).
7. Prepared academic documentation: `PROJECT_REPORT.md` and `PRESENTATION_SLIDES.md`.
8. Pushed all updates to the official GitHub repository.

---

## 2. Three-Tier Architectural Decomposition

The application architecture enforces strict object composition and separation of concerns:

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

## 3. Defensive Validation Engineering

### 3.1 Stream Failure Recovery
Standard C++ `cin >> var` fails when the user enters non-numeric text (e.g. `"abc"`), entering an error state (`failbit`) that causes infinite loops. Version 3.0 recovers automatically:

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

### 3.2 Power Domain Integrity
```cpp
bool InputValidator::isValidPower(double base, double exponent) const {
    // 0^0 is indeterminate
    if (base == 0.0 && exponent == 0.0) return false;
    // 0^(-k) is division by zero
    if (base == 0.0 && exponent < 0.0) return false;
    // Negative base with non-integer exponent yields complex number
    if (base < 0.0 && std::floor(exponent) != exponent) return false;
    return true;
}
```

### 3.3 Tangent Asymptotic Singularity Guard
Because $\pi$ cannot be stored with infinite precision in binary float format, $\cos(90^\circ) \approx 6.12 \times 10^{-17}$ rather than true zero, yielding an erroneous output $\tan(90^\circ) \approx 1.63 \times 10^{16}$. Version 3 guards against this using a cosine epsilon threshold:
```cpp
bool InputValidator::isValidTangent(double degrees) const {
    constexpr double PI = 3.14159265358979323846;
    double radians = degrees * (PI / 180.0);
    return std::fabs(std::cos(radians)) > 1e-12;
}
```

---

## 4. Test Verification Summary (30 Test Cases)

| Test Category | Operations Covered | Key Validation Scenarios Tested | Outcome |
| :--- | :--- | :--- | :---: |
| **Arithmetic** | `+`, `-`, `*`, `/` | Negative result subtraction, decimal multiplication, division by zero | **100% PASS** |
| **Scientific** | Square, $\sqrt{x}$, $b^e$, $\%$ | Negative square root rejection, $0^0$ rejection, complex power rejection | **100% PASS** |
| **Trigonometric** | $\sin$, $\cos$, $\tan$ | Normalization of $\sin(180^\circ)=0$, $\cos(90^\circ)=0$, rejection of $\tan(90^\circ), \tan(270^\circ)$ | **100% PASS** |
| **Logarithmic** | $\log_{10}$, $\ln$ | $\log_{10}(100)=2$, $\ln(e)=1$, rejection of $\le 0$ inputs | **100% PASS** |
| **Stream Parsing** | Menu choices, operand entry | Recovery from strings `"abc"`, `"xyz"`, out-of-range menu options | **100% PASS** |

*(Refer to `test_cases.md` for the complete 30-row verification table).*

---

## 5. Git Version Control Evidence

* **Commit Hash:** `25dc205`
* **Commit Date:** `2026-11-17 18:00:00 +0530`
* **Commit Message:** `feat(v3.0): full defensive input validation, domain edge case guards, and academic report (Evaluation 3)`
* **Follow-up Commit:** `9b7779f` (`docs: add 10-minute final presentation slide deck and viva prep guide`)
* **Repository Link:** [https://github.com/Tarakesh-doctordoom/Scientific-Calculator](https://github.com/Tarakesh-doctordoom/Scientific-Calculator)

---

## 6. Evaluation 3 Rubric & Self-Assessment

| Evaluation Criteria | Maximum Marks | Marks Awarded | Remarks |
| :--- | :---: | :---: | :--- |
| **Defensive Input Validation** | 1.5 | 1.5 | Stream corruption recovery, buffer purging, crash immunity. |
| **Domain Constraint Handling** | 1.0 | 1.0 | Strict checks for $0^0$, negative roots, log $\le 0$, tan singularity. |
| **Modular Multi-File Code** | 0.5 | 0.5 | Clean separation into `.h` and `.cpp` across all classes. |
| **Git Repository & Code Push** | 1.0 | 1.0 | Version 3 commit verified and pushed to GitHub. |
| **Total** | **4.0** | **4.0** | **Satisfies all Evaluation 3 requirements.** |

---

## 7. Readiness for Final Presentation (24/25 Nov 2026)

All prerequisites for the final 5-mark presentation milestone are fully prepared:
* Complete academic report: `PROJECT_REPORT.md`
* 10-minute slide deck with Viva/Q&A preparation: `PRESENTATION_SLIDES.md`
* Live GitHub repository ready for demonstration.

---

**Evaluator Signature:** ___________________________  
**Date:** ____ / 11 / 2026
