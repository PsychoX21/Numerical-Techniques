# Week 3: Numerical Techniques in Physics  

Welcome to the Week 3 report for **Numerical Techniques in Physics**. This README provides a detailed overview of the problems solved, methods used, observations made, and results obtained during the third week.

---

## **Problem 1: Solving Poisson's Equation in 2D**  

### Task:  
Solve the Poisson equation in 2D:  
∂²U/∂x² + ∂²U/∂y² = -ρ(x, y)
for a set of charge configurations using the **Finite-Difference Method (FDM)**. 

for a set of charge configurations using the **Finite-Difference Method (FDM)**.  

### Method Overview:  
1. **Discretization**:  
   - The second derivatives were approximated using finite differences:  
     ∂²U/∂x² ≈ [U(x+h) - 2U(x) + U(x-h)] / h²
   - Similarly for ∂²U/∂y².  

2. **Matrix Formulation**:  
   - The grid was converted into a sparse matrix representation to solve the system of equations efficiently.  

3. **Iterative Solution**:  
   - Used **Gauss-Seidel** method to solve the system iteratively until convergence was achieved.  

### Results:   
   - Solved the equation for different charge distributions.  
   - Visualized the potential field for each configuration using GNUplot.  

---
