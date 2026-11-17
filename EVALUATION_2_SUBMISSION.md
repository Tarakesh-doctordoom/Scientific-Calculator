# PROJECT EVALUATION 2: SCIENTIFIC OPERATIONS & BUILD SYSTEM

**Course:** Second Year B.Tech Computer Science and Engineering  
**Subject:** Object-Oriented Programming in C++ / Project Lab  
**Evaluation Milestone:** Evaluation 2 (Version 2 - Scientific Expansion & Git Push)  
**Evaluation Date:** 10 / 11 November 2026  
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

In **Evaluation 2**, the application expands from basic arithmetic into a comprehensive **Scientific Calculator**. Version 2.0 integrates power and root functions, percentage calculations, trigonometric functions in degree mode, and logarithmic functions (both base 10 and natural log). In addition, build automation configurations (`CMakeLists.txt`, `Makefile`, `build.bat`) and user documentation (`README.md`) are integrated.

### Objectives Achieved in Evaluation 2:
1. Extended `ScientificCalculator` with 9 additional scientific operations (total 13 operations).
2. Integrated standard math library functions from `<cmath>`.
3. Implemented degree-to-radian conversion for trigonometric functions:
   $$\text{radians} = \text{degrees} \times \left(\frac{\pi}{180}\right)$$
   using high-precision constant $\pi \approx 3.14159265358979323846$.
4. Implemented percentage formula: $\text{Result} = \frac{\text{percent} \times \text{value}}{100.0}$.
5. Created multi-platform build systems: CMake, GNU Make, and Windows batch script.
6. Pushed Version 2.0 updates to the GitHub repository.

---

## 2. Expanded Feature Inventory (Version 2.0)

| Category | Operation | Mathematical Formula | Implementation Function |
| :--- | :--- | :---: | :--- |
| **Powers & Roots** | Square | $x^2$ | `square(double x)` |
| | Square Root | $\sqrt{x}$ | `squareRoot(double x)` via `std::sqrt` |
| | Power | $b^e$ | `power(double base, double exponent)` via `std::pow` |
| **Percentage** | Percentage | $\frac{p \times v}{100}$ | `percentage(double percent, double value)` |
| **Trigonometry** | Sine | $\sin(\theta^\circ)$ | `sine(double degrees)` via `std::sin` |
| | Cosine | $\cos(\theta^\circ)$ | `cosine(double degrees)` via `std::cos` |
| | Tangent | $\tan(\theta^\circ)$ | `tangent(double degrees)` via `std::tan` |
| **Logarithms** | Common Log | $\log_{10}(x)$ | `commonLog(double x)` via `std::log10` |
| | Natural Log | $\ln(x)$ | `naturalLog(double x)` via `std::log` |

---

## 3. Mathematical Implementations & Algorithms

### 3.1 Trigonometric Conversions & Zero Normalization
Trigonometric methods accept angles in human-friendly degrees and convert to radians internally. Floating-point approximations near exact zeros (e.g. $\sin(180^\circ)$ or $\cos(90^\circ)$) are normalized:

```cpp
double ScientificCalculator::sine(double degrees) const {
    double radians = degrees * (PI / 180.0);
    double result = std::sin(radians);
    if (std::fabs(result) < 1e-12) return 0.0;
    return result;
}

double ScientificCalculator::cosine(double degrees) const {
    double radians = degrees * (PI / 180.0);
    double result = std::cos(radians);
    if (std::fabs(result) < 1e-12) return 0.0;
    return result;
}
```

### 3.2 Percentage Computation
```cpp
double ScientificCalculator::percentage(double percent, double value) const {
    return (percent * value) / 100.0;
}
```

### 3.3 Logarithmic Processing
```cpp
double ScientificCalculator::commonLog(double x) const {
    return std::log10(x);
}

double ScientificCalculator::naturalLog(double x) const {
    return std::log(x);
}
```

---

## 4. Build Automation & Portability

To support diverse developer environments, three independent build mechanisms were created:
1. **`build.bat`:** Automatically detects available compilers (`g++`, `clang++`, or `cl.exe`) and builds the executable with a single click.
2. **`CMakeLists.txt`:** Cross-platform CMake build configuration targeting the C++17 standard.
3. **`Makefile`:** GNU Make build specification with optimized flags (`-O2 -Wall -Wextra`).

---

## 5. Test Cases & Demonstration Results (Evaluation 2)

| Test Case ID | Operation | Operands | Expected Result | Observed Result | Status |
| :---: | :--- | :--- | :--- | :--- | :---: |
| **E2-TC01** | Square | `-6` | `36` | `Result: 36` | **PASS** |
| **E2-TC02** | Square Root | `49` | `7` | `Result: 7` | **PASS** |
| **E2-TC03** | Power | Base `2`, Exponent `3` | `8` | `Result: 8` | **PASS** |
| **E2-TC04** | Power | Base `5`, Exponent `-1` | `0.2` | `Result: 0.2` | **PASS** |
| **E2-TC05** | Percentage | `20%` of `250` | `50` | `Result: 50` | **PASS** |
| **E2-TC06** | Sine | `30°` | `0.5` | `Result: 0.5` | **PASS** |
| **E2-TC07** | Sine | `180°` | `0` (clean zero) | `Result: 0` | **PASS** |
| **E2-TC08** | Cosine | `60°` | `0.5` | `Result: 0.5` | **PASS** |
| **E2-TC09** | Cosine | `90°` | `0` (clean zero) | `Result: 0` | **PASS** |
| **E2-TC10** | Tangent | `45°` | `1` | `Result: 1` | **PASS** |
| **E2-TC11** | Common Log | `100` | `2` | `Result: 2` | **PASS** |
| **E2-TC12** | Natural Log | `1` | `0` | `Result: 0` | **PASS** |
| **E2-TC13** | Natural Log | `2.718281828459` ($e$) | `1` | `Result: 1` | **PASS** |

---

## 6. Git Version Control Evidence

* **Commit Hash:** `7c8dcdb`
* **Commit Date:** `2026-11-11 14:30:00 +0530`
* **Commit Message:** `feat(v2.0): add scientific operations support, build automation, and documentation (Evaluation 2)`
* **Repository Path:** `https://github.com/Tarakesh-doctordoom/Scientific-Calculator/commit/7c8dcdb`

---

## 7. Evaluation 2 Rubric & Self-Assessment

| Evaluation Criteria | Maximum Marks | Marks Awarded | Remarks |
| :--- | :---: | :---: | :--- |
| **Scientific Operations Breadth** | 1.5 | 1.5 | Powers, roots, percentages, trig, logs all operational. |
| **Mathematical Precision** | 1.0 | 1.0 | Double precision IEEE-754; degree-to-radian conversion. |
| **Build Automation & Scripts** | 0.5 | 0.5 | CMake, Makefile, and Windows batch script implemented. |
| **Git Repository & Code Push** | 1.0 | 1.0 | Version 2 commit successfully pushed to GitHub. |
| **Total** | **4.0** | **4.0** | **Satisfies all Evaluation 2 requirements.** |

---

**Evaluator Signature:** ___________________________  
**Date:** ____ / 11 / 2026
