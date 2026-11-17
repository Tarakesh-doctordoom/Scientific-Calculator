# PROJECT EVALUATION 1: FIRST CUT / MVP VERSION

**Course:** Second Year B.Tech Computer Science and Engineering  
**Subject:** Object-Oriented Programming in C++ / Project Lab  
**Evaluation Milestone:** Evaluation 1 (First Cut / MVP Version & Git Push)  
**Evaluation Date:** 03 / 04 November 2026  
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

The objective of **Evaluation 1** is to develop, demonstrate, and commit the **Minimum Viable Product (MVP)** of the Scientific Calculator Application in C++. The MVP establishes the core architectural scaffolding, initial object-oriented class organization, essential console interaction loop, and fundamental arithmetic computations.

### Objectives Achieved in Evaluation 1:
1. Established the modular C++ project skeleton.
2. Formulated the fundamental OOP design: `CalculatorApp` coordinating the execution lifecycle and user interaction.
3. Implemented foundational binary arithmetic operations: Addition, Subtraction, Multiplication, and Division.
4. Integrated continuous user flow via a `do-while` menu loop with option `0` for clean exit.
5. Established the Git version control repository with the initial MVP commit.

---

## 2. Features Implemented in Version 1.0 (MVP)

| Operation | Operator / Math Function | Input Operands | Description / Implementation |
| :--- | :---: | :---: | :--- |
| **Addition** | $a + b$ | Two `double` numbers | Computes sum of operands. |
| **Subtraction** | $a - b$ | Two `double` numbers | Computes difference between operands. |
| **Multiplication** | $a \times b$ | Two `double` numbers | Computes product of operands. |
| **Division** | $a / b$ | Two `double` numbers | Computes quotient; basic divisor check. |
| **Application Loop** | Menu / Switch | Option `0` - `4` | Allows repeated calculations until exit. |

---

## 3. Architecture & Class Decomposition (MVP Phase)

In this first version, the program defines the base classes and interaction loop:

```
+----------------------------------------------------+
|                   CalculatorApp                    |
+----------------------------------------------------+
| - calculator : ScientificCalculator                |
+----------------------------------------------------+
| + run() : void                                     |
| + displayMenu() : void                             |
| + performOperation(choice : int) : void            |
| + displayResult(result : double) : void            |
+----------------------------------------------------+
                          |
             contains and | uses
                          v
+----------------------------------------------------+
|                ScientificCalculator                |
+----------------------------------------------------+
| + add(a : double, b : double) : double             |
| + subtract(a : double, b : double) : double        |
| + multiply(a : double, b : double) : double        |
| + divide(a : double, b : double) : double          |
+----------------------------------------------------+
```

### Key OOP Principles Demonstrated:
* **Encapsulation:** Computation methods are grouped within `ScientificCalculator`; UI coordination is encapsulated in `CalculatorApp`.
* **Separation of Concerns:** `ScientificCalculator` performs computations on double-precision numbers without direct stream I/O.
* **Control Structures:** Uses `while` loop for application continuity and `switch-case` for operation dispatching.

---

## 4. MVP Source Code Excerpts

### Arithmetic Calculation Engine:
```cpp
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
```

### Execution Loop:
```cpp
void CalculatorApp::run() {
    int choice = -1;
    while (choice != 0) {
        displayMenu();
        std::cin >> choice;
        if (choice == 0) {
            std::cout << "\nExiting application. Thank you!\n";
            break;
        }
        performOperation(choice);
    }
}
```

---

## 5. Test Cases & Demonstration Results (Evaluation 1)

| Test Case ID | Operation | Operands | Expected Output | Observed Output | Result |
| :---: | :--- | :--- | :--- | :--- | :---: |
| **E1-TC01** | Addition | `12`, `8` | `20` | `Result: 20` | **PASS** |
| **E1-TC02** | Subtraction | `5`, `9` | `-4` | `Result: -4` | **PASS** |
| **E1-TC03** | Multiplication | `2.5`, `4` | `10` | `Result: 10` | **PASS** |
| **E1-TC04** | Division | `15`, `3` | `5` | `Result: 5` | **PASS** |
| **E1-TC05** | Division by Zero | `15`, `0` | Prevent division | `Cannot divide by zero.` | **PASS** |
| **E1-TC06** | Exit Program | `0` | Exit message | Program exits cleanly | **PASS** |

---

## 6. Git Version Control Evidence

* **Commit Hash:** `4149ebb`
* **Commit Date:** `2026-11-04 11:00:00 +0530`
* **Commit Message:** `feat(v1.0): MVP version - core architecture and arithmetic operations (Evaluation 1)`
* **Repository Path:** `https://github.com/Tarakesh-doctordoom/Scientific-Calculator/commit/4149ebb`

---

## 7. Evaluation 1 Rubric & Self-Assessment

| Evaluation Criteria | Maximum Marks | Marks Awarded | Remarks |
| :--- | :---: | :---: | :--- |
| **Working MVP Application** | 1.5 | 1.5 | Basic arithmetic calculations functioning accurately. |
| **Object-Oriented Design** | 1.0 | 1.0 | Clear class separation between App and Math logic. |
| **Interactive Menu Loop** | 0.5 | 0.5 | Continuous calculation cycle with graceful exit. |
| **Git Repository & Code Push** | 1.0 | 1.0 | Repository initialized, structured commit pushed. |
| **Total** | **4.0** | **4.0** | **Satisfies all Evaluation 1 requirements.** |

---

**Evaluator Signature:** ___________________________  
**Date:** ____ / 11 / 2026
