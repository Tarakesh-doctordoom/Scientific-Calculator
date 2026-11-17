# Test Cases and Verification Log
## Scientific Calculator Application in C++

**Course:** Second Year B.Tech CSE Project  
**Authors:**
- **Valurouth Tarakesh** (2501020034)
- **Kumawat Akshat Sujaram** (2501020035)

---

## 1. Overview

This document records the comprehensive test suite executed for the **Scientific Calculator Application in C++**. Testing covers basic arithmetic, scientific operations, trigonometric angles, logarithms, mathematical edge cases, and robust stream parsing.

---

## 2. Test Execution Matrix

| Test ID | Category | Operation Tested | Input Data | Expected Output | Observed Output | Status |
| :---: | :---: | :--- | :--- | :--- | :--- | :---: |
| **TC-01** | Arithmetic | Addition (Positive Integers) | `12`, `8` | `Result: 20` | `Result: 20` | **PASS** |
| **TC-02** | Arithmetic | Subtraction (Negative Result) | `5`, `9` | `Result: -4` | `Result: -4` | **PASS** |
| **TC-03** | Arithmetic | Multiplication (Decimals) | `2.5`, `4` | `Result: 10` | `Result: 10` | **PASS** |
| **TC-04** | Arithmetic | Division (Standard) | `15`, `3` | `Result: 5` | `Result: 5` | **PASS** |
| **TC-05** | Arithmetic | Division by Zero | `15`, `0` | `Cannot divide by zero.` | `Cannot divide by zero.` | **PASS** |
| **TC-06** | Scientific | Square (Negative Operand) | `-6` | `Result: 36` | `Result: 36` | **PASS** |
| **TC-07** | Scientific | Square Root (Exact Integer) | `49` | `Result: 7` | `Result: 7` | **PASS** |
| **TC-08** | Scientific | Square Root (Negative) | `-9` | `Require a non-negative number.` | `Require a non-negative number.` | **PASS** |
| **TC-09** | Scientific | Power (Standard Positive) | `2`, `3` | `Result: 8` | `Result: 8` | **PASS** |
| **TC-10** | Scientific | Power (Negative Base, Int Exp) | `-2`, `3` | `Result: -8` | `Result: -8` | **PASS** |
| **TC-11** | Scientific | Power (Negative Base, Non-Int) | `-4`, `0.5` | Rejection: Unsupported power | `Unsupported powers: negative base with non-integer exponent...` | **PASS** |
| **TC-12** | Scientific | Power (Zero Base, Zero Exp) | `0`, `0` | Rejection: 0^0 indeterminate | `Unsupported powers: negative base with non-integer exponent...` | **PASS** |
| **TC-13** | Scientific | Power (Zero Base, Negative Exp) | `0`, `-2` | Rejection: division by zero | `Unsupported powers: negative base with non-integer exponent...` | **PASS** |
| **TC-14** | Scientific | Percentage | `20`, `250` | `Result: 50` | `Result: 50` | **PASS** |
| **TC-15** | Trigonometry| Sine (30 Degrees) | `30` | `Result: 0.5` | `Result: 0.5` | **PASS** |
| **TC-16** | Trigonometry| Sine (180 Degrees) | `180` | `Result: 0` | `Result: 0` | **PASS** |
| **TC-17** | Trigonometry| Cosine (60 Degrees) | `60` | `Result: 0.5` | `Result: 0.5` | **PASS** |
| **TC-18** | Trigonometry| Cosine (90 Degrees) | `90` | `Result: 0` | `Result: 0` | **PASS** |
| **TC-19** | Trigonometry| Tangent (45 Degrees) | `45` | `Result: 1` | `Result: 1` | **PASS** |
| **TC-20** | Trigonometry| Tangent (90 Degrees) | `90` | Reject undefined angle | `Reject undefined angle; tangent is undefined at 90° + 180° × k.` | **PASS** |
| **TC-21** | Trigonometry| Tangent (270 Degrees) | `270` | Reject undefined angle | `Reject undefined angle; tangent is undefined at 90° + 180° × k.` | **PASS** |
| **TC-22** | Logarithm | Common Log (Base 10) | `100` | `Result: 2` | `Result: 2` | **PASS** |
| **TC-23** | Logarithm | Common Log (Zero Input) | `0` | `Require a positive number.` | `Require a positive number.` | **PASS** |
| **TC-24** | Logarithm | Common Log (Negative Input) | `-10` | `Require a positive number.` | `Require a positive number.` | **PASS** |
| **TC-25** | Logarithm | Natural Log (Base e) | `1` | `Result: 0` | `Result: 0` | **PASS** |
| **TC-26** | Logarithm | Natural Log of e (2.71828) | `2.718281828459` | `Result: 1` | `Result: 1` | **PASS** |
| **TC-27** | Stream I/O | Non-numeric Menu Choice | `"abc"`, then `1` | Prompt re-issued for option | Discards `"abc"`, accepts `1` | **PASS** |
| **TC-28** | Stream I/O | Out-of-bounds Menu Choice | `99`, then `4` | Prompt re-issued for option | Discards `99`, accepts `4` | **PASS** |
| **TC-29** | Stream I/O | Non-numeric Operand Input | `"xyz"`, then `25` | Prompt re-issued for number | Discards `"xyz"`, accepts `25` | **PASS** |
| **TC-30** | Control Flow| Exit Option | `0` | Program terminates cleanly | Displays exit message and terminates | **PASS** |

---

## 3. Boundary & Error Verification Summary

1. **Division by Zero:** Correctly intercepted prior to floating point division.
2. **Negative Roots:** Prevented before calling `std::sqrt()`.
3. **Logarithmic Singularities:** Values $\le 0$ strictly rejected.
4. **Tangent Asymptotes:** Evaluated using cosine tolerance threshold $|\cos(\text{rad})| > 10^{-12}$, successfully catching $90^\circ$, $270^\circ$, and general $(90 + 180k)^\circ$.
5. **Indeterminate Powers:** Successfully rejects $0^0$, $0^{-n}$, and $(-x)^y$ where $y$ is non-integer.
6. **Finite Floating-Point Result:** Verified with `std::isfinite()`.
