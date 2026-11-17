# Final Presentation Slide Deck (10-Minute Presentation)
## Scientific Calculator Application in C++

**Course:** Second Year B.Tech Computer Science and Engineering  
**Academic Year:** 2026-2027  
**Project Presenters:**
- **Valurouth Tarakesh** (Roll No: `2501020034`)
- **Kumawat Akshat Sujaram** (Roll No: `2501020035`)

---

## Slide 1: Title & Project Identification
* **Project Title:** Scientific Calculator Application in C++
* **Course:** Object-Oriented Programming with C++ (2nd Year B.Tech CSE)
* **Team Members:**
  * Valurouth Tarakesh (2501020034)
  * Kumawat Akshat Sujaram (2501020035)
* **Supervisor / Evaluator:** Department of Computer Science & Engineering

---

## Slide 2: Problem Statement & Objectives
* **Challenge:** Conventional console calculator implementations often crash upon receiving non-numeric characters, silently produce `NaN`/`inf` upon domain violations, or couple UI logic tightly with computation.
* **Objectives:**
  1. Develop a menu-driven, interactive scientific calculator in standard C++17.
  2. Implement strict mathematical domain guards (division by zero, negative roots, logarithms, tangent singularities).
  3. Enforce industrial-grade defensive input parsing that recovers gracefully without crashing.
  4. Demonstrate pure Object-Oriented Programming (OOP) principles: class modularity, composition, and single responsibility.

---

## Slide 3: System Architecture & OOP Principles
* **Separation of Concerns (Single Responsibility Principle):**
  * `ScientificCalculator`: Pure computation engine. Zero console I/O.
  * `InputValidator`: Stream parsing, input cleansing, and domain boundary validation.
  * `CalculatorApp`: Master workflow coordinator, menu display, and result presentation.
* **Composition over Inheritance:**
  * `CalculatorApp` "has-a" `ScientificCalculator` and `InputValidator` as private encapsulated members.

---

## Slide 4: Supported Operations Inventory (13 Operations + Exit)
* **Arithmetic Operations:**
  * Addition (`+`), Subtraction (`-`), Multiplication (`*`), Division (`/` with non-zero check).
* **Scientific Operations:**
  * Square ($x^2$), Square Root ($\sqrt{x}$ with $x \ge 0$), Power ($b^e$), Percentage ($\frac{p \times v}{100}$).
* **Trigonometric Functions (Degree Mode):**
  * Sine ($\sin\theta$), Cosine ($\cos\theta$), Tangent ($\tan\theta$ with singularity check).
* **Logarithmic Functions:**
  * Common Logarithm ($\log_{10}x$ with $x > 0$), Natural Logarithm ($\ln x$ with $x > 0$).
* **Control:**
  * Option 0 exits cleanly.

---

## Slide 5: Deep Dive: Mathematical Domain Protections
1. **Division by Zero:** Intercepts denominator $b = 0$ before hardware execution.
2. **Negative Square Root:** Rejects $x < 0$ to prevent complex imaginary `NaN`.
3. **Power Boundary Conditions:**
   * Rejects indeterminate form $0^0$.
   * Rejects zero to negative exponents ($0^{-k} = \frac{1}{0^k}$).
   * Rejects negative base with fractional exponent ($(-4)^{0.5} = 2i$).
4. **Tangent Singularity Guard:**
   * $\tan(\theta)$ approaches $\pm\infty$ at $90^\circ + 180^\circ \times k$.
   * In floating-point math, $\cos(90^\circ) \approx 6.12 \times 10^{-17} \neq 0$.
   * We apply a cosine tolerance: $|\cos(\text{rad})| > 10^{-12}$ to catch all asymptotic singularity points accurately.
5. **Finite Range Verification:**
   * Verifies outputs with `std::isfinite(result)` to protect against overflow to `+Infinity`.

---

## Slide 6: Robust Stream Cleansing & Crash Immunity
* **Standard Pitfall:** Entering letters (e.g. `"abc"`) into `cin >> value` sets `failbit`, causing perpetual infinite loops.
* **Our Defensive Solution:**
  ```cpp
  if (!(std::cin >> value)) {
      std::cin.clear(); // Reset error state flags
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard buffer
  }
  ```
* Guaranteed crash-free execution regardless of malformed user keystrokes.

---

## Slide 7: Live Demo & Test Verification Matrix
* 30 comprehensive test cases executed across all operation types.
* **Sample Verifications:**
  * Normal: `12 + 8 = 20`, `2.5 * 4 = 10`, `2^3 = 8`, `sin(30°) = 0.5`.
  * Normalization: `sin(180°) = 0`, `cos(90°) = 0`.
  * Exception Handling: `15 / 0` -> `"Cannot divide by zero."`
  * Singularity: `tan(90°)` -> `"Reject undefined angle."`
  * Stream Recovery: Entering `"xyz"` reprompts cleanly.

---

## Slide 8: Development Evolution (Git Milestone History)
* **v1.0 (Evaluation 1 - Nov 4):** Core MVP arithmetic operations and basic menu loop.
* **v2.0 (Evaluation 2 - Nov 11):** Integration of scientific operations (powers, roots, percentage, trig, logs) and build automation (CMake/Make/Batch).
* **v3.0 (Evaluation 3 - Nov 17):** Industrial-grade validation (`InputValidator`), domain edge case guards, multi-file separation, complete test suite, and academic report.

---

## Slide 9: Conclusion & Key Learnings
* **Takeaways:**
  * Clean separation of concerns simplifies testing and debugging.
  * Defensive I/O programming is vital for robust terminal software.
  * Floating-point nuances (epsilon tolerances) are essential for accurate mathematical computing.
* **Future Work:**
  * Adding an expression parser (Shunting-yard algorithm).
  * Graphical user interface (GUI) using Qt or Dear ImGui.

---

## Slide 10: Anticipated Viva / Q&A Questions & Model Answers
* **Q1: Why did you separate `ScientificCalculator` from `InputValidator`?**
  * *Answer:* To satisfy the Single Responsibility Principle. `ScientificCalculator` is a pure mathematical library that can be reused in any UI (CLI, GUI, WebAssembly) without altering computational code.
* **Q2: Why does `tan(90°)` fail in standard C++ math unless guarded?**
  * *Answer:* Standard IEEE-754 floating point cannot store $\pi$ with infinite precision; thus $\cos(90^\circ) \approx 6.12 \times 10^{-17}$, leading to a false pseudo-result ($1.63 \times 10^{16}$) instead of reporting undefined. Our cosine epsilon guard detects this singularity.
* **Q3: How does the application avoid infinite loops on invalid input?**
  * *Answer:* When `std::cin` fails, `std::cin.clear()` resets the stream state flags and `std::cin.ignore()` purges all corrupt characters from the input buffer.
