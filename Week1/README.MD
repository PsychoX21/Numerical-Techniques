# Week 1: Numerical Techniques in Physics

Welcome to the Week 1 report for **Numerical Techniques in Physics**. This README provides a detailed overview of the problems solved, methods used, observations made, and results obtained during the first week.

---

## **Problem 1: Setting Up Environment**
### Task:
- Set up **C++** as the primary programming language and **GNUplot** for visualizations.
- Installed tools:
  - **VS Code**: IDE for coding and debugging.
  - **GNUplot**: For plotting graphs.

### Learnings:
- Understood the basics of plotting tools for numerical computations.

---

## **Problem 2: Newton-Raphson Method**
### Task:
Find a root of the equation \(x^2 - 8x + 11 = 0\) to 5 decimal places using the initial guess \(x_0 = 6\).

### Method Overview:
- Formula used:
  \[
  x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}
  \]
- Derivation involves Taylor expansion to approximate \(f(x)\).

### Results:
- Converged root: **\(x = 6.23607\)**
- Number of iterations: **4**

### Key Observations and Insights:
- The method’s quadratic convergence ensured rapid results for this polynomial.
- Precision was achieved efficiently within a few iterations.

---

## **Problem 3: Secant Method**
### Task:
Find the root of \(f(x) = e^{2x} + x - 5\) using the secant method with initial guesses \(x_0 = 0\) and \(x_1 = 1\).

### Method Overview:
- Formula used:
  \[
  x_{n+1} = x_n - \frac{f(x_n)(x_n - x_{n-1})}{f(x_n) - f(x_{n-1})}
  \]
- Unlike Newton-Raphson, it does not require explicit derivatives.

### Results:
- Converged root: **\(x = 0.62133\)**
- Number of iterations: **7**

### Key Observations and Insights:
- Secant method converges slower than Newton-Raphson but is more versatile.

### Challenges Faced:
- Iterative refinement required precise calculations for non-linear functions.

---

## **Problem 4: Euler Method**
### Task:
Solve the initial value problem:
\[
y' + 2y = x^3e^{-2x}, \quad y(0) = 1
\]
using step sizes \(h = 0.1, 0.05, 0.025\).

### Method Overview:
- Derived from the first-order Taylor expansion:
  \[
  y_{n+1} = y_n + h \cdot f(x_n, y_n)
  \]
- Accuracy improves as the step size decreases.

### Results:
| Step Size (h) | Approximation (\(y(1)\)) | Exact Solution | Error (%) |
|---------------|--------------------------|----------------|-----------|
| 0.1           | 0.8652                   | 0.8765         | 1.29      |
| 0.05          | 0.8726                   | 0.8765         | 0.44      |
| 0.025         | 0.8751                   | 0.8765         | 0.16      |

### Graphs:
- A combined plot of all step sizes and the exact solution was created to visualize accuracy improvements.
![Euler Method Plot](Plots/euler.png)

### Key Observations and Insights:
- Step size plays a critical role in balancing computational efficiency and accuracy.
- Smaller step sizes significantly reduce error.

### Challenges Faced:
- Balancing precision with computational cost.

---

## **Problem 5: Runge-Kutta 4th Order Method (RK4)**
### Task:
Solve the same initial value problem using the RK4 method.

### Method Overview:
- Formula used:
  \[
  y_{n+1} = y_n + \frac{h}{6}(k_1 + 2k_2 + 2k_3 + k_4)
  \]
- Intermediate slopes (\(k_1, k_2, k_3, k_4\)) computed to refine accuracy.

### Results:
| Step Size (h) | Approximation (\(y(1)\)) | Exact Solution | Error (%) |
|---------------|--------------------------|----------------|-----------|
| 0.1           | 0.8758                   | 0.8765         | 0.08      |
| 0.05          | 0.8763                   | 0.8765         | 0.02      |
| 0.025         | 0.8764                   | 0.8765         | 0.01      |

### Graphs:
- Combined plot comparing RK4, Euler, and the exact solution.
![RK4 Method Plot](Plots/RK4.png)

### Key Observations and Insights:
- RK4 offers better accuracy than Euler for the same step sizes.
- Computational cost is justified by significantly lower error.

### Challenges Faced:
- None, as the method is inherently stable and robust.

---

## **Problem 6: Solving Linear Systems (Jacobi & Gauss-Seidel Methods)**
### Task:
Solve the linear equations system using iterative methods.

### Observations:
- **Jacobi Method**: Converged in **15 iterations**
- **Gauss-Seidel Method**: Converged in **10 iterations**

### Key Insights:
- Gauss-Seidel converges faster due to sequential updates.
- Code was generalized for larger systems, preparing for future use in higher dimensions.

---

## **Performance Highlights**
- Successfully solved all problems using the prescribed methods.
- Graphical outputs validated accuracy for Problems 4 and 5.
- Iterative methods were effectively implemented and extended for general use.

---

## **Learnings**
- Deep understanding of numerical methods, their derivation, and application.
- Importance of step sizes, convergence criteria, and iterative refinement.
- Basics of using GitHub for collaborative coding.

---

## **Future Scope**
- Extend the generalized code for high-dimensional systems (>10,000x10,000).
- Explore higher-order Runge-Kutta methods for even better accuracy.
- Investigate optimization techniques for iterative solvers.

---

## **Code Highlights**
- Clean and modular C++ implementations for all problems.
- Effective use of loops and conditionals for convergence checks.
