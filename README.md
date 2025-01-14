# Computational Physics Projects: Numerical Techniques in Physics

Welcome to my repository for the **Numerical Techniques in Physics** project under the guidance of **Apurv Keer**, a fourth-year student in the Department of Physics at IIT Bombay. This repository contains solutions and analysis for weekly assignments provided as part of the project, using **C++** as the primary programming language.

## 📜 Project Overview

This project focuses on implementing numerical methods to solve physics problems. It provides hands-on experience with coding numerical algorithms, plotting results, and analyzing outcomes. Over the course of four weeks, I will work on various tasks and document the results here.

Each week's work is organized into its respective folder, with solutions to assigned problems, and relevant plots.

---

## 📚 Weekly Assignments

### Week 1: Foundations of Numerical Techniques

* Setup: Configured C++ environment with VS Code and GNUplot.
* Newton-Raphson Method: Found roots of a polynomial equation.
* Secant Method: Determined roots for a non-linear equation using iterative approximation.
* Euler's Method: Solved a first-order ODE with different step sizes, comparing results to the exact solution.
* RK4 Method: Implemented the Runge-Kutta 4th order method and compared accuracy to Euler’s method.
* Solving Linear Systems: Used Jacobi and Gauss-Seidel methods to solve a set of linear equations iteratively.

### Week 2: Second Order ODEs with some applications

* Solving second-order ODEs with Euler and RK4.
* Van der Pol Oscillator: Simulated and analyzed the oscillator’s behavior for varying parameters.
* Lorenz Attractor: Explored chaotic dynamics and sensitivity to initial conditions.

### Week 3: Solving Poisson's Equation with Finite-Difference Method

* Objective: Solve the 2D Poisson equation:
∂²U/∂x² + ∂²U/∂y² = -ρ(x, y)
for various charge configurations using numerical methods.
* Finite-Difference Approximation: Discretized the partial derivatives using a grid and approximated the second derivatives using:
∂²U/∂x² ≈ [U(x+h) - 2U(x) + U(x-h)] / h²
Converted the equation into a system of linear equations.

### **Week 4: Hydrogen Atom Assignment**  
- **Objective**: Numerically solve the Schrödinger equation for the hydrogen atom to compute energy eigenvalues and eigenstates.  
- **Hamiltonian**: Reduced the Hamiltonian to a single-particle problem:  
  H_CoM = -(ħ² / 2μ) ∇² - (e² / (4πε₀ r))
where `μ` is the reduced mass and `r` is the displacement vector between the electron and proton.  
- **Finite-Difference Method**:  
- Discretized the Laplacian operator using:  
  ∂²U/∂x² ≈ (U[i+1] + U[i-1] - 2U[i]) / Δx²
  and using similar expressions for other dimensions
- Converted the Schrödinger equation into a sparse matrix representation.  
- **Eigenvalue Computation**:  
- Implemented the power iteration algorithm to compute the ground state and excited states.  
- **Results**:  
- Numerically calculated ground state energy: **13.16 eV** (theoretical value: **-13.6 eV**).  
- Visualized wavefunctions for the ground state and several excited states.  

---
