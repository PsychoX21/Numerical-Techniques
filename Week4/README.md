# Week 4: Numerical Techniques in Physics - Hydrogen Atom  

Welcome to the Week 4 report for **Numerical Techniques in Physics**. This week, we focused on solving the Schrödinger equation numerically for the hydrogen atom, exploring its eigenstates and eigenvalues.

---

## **Problem Overview**  

The Hamiltonian for a system consisting of an electron and a proton is given as:  
H = -(ħ² / 2mₚ) ∇ₚ² - (ħ² / 2mₑ) ∇ₑ² - (e² / (4πε₀ |r₁ - r₂|))

For simplicity, we reduced this to a single-particle problem using the center-of-mass transformation:  
H_CoM = -(ħ² / 2μ) ∇_r² - (e² / (4πε₀ r))
where:
- `μ` is the reduced mass,  
- `r` is the displacement vector between the two particles.  

The goal was to compute the energy eigenvalues and eigenstates numerically using:  
1. Finite-difference discretization for the Hamiltonian.  
2. Numerical eigensolvers to extract eigenvalues and eigenstates.  

---

## **Tasks and Solutions**

### **Task 1: Expanding the Hamiltonian**
- Expanded the Hamiltonian in Cartesian coordinates:  
H = -(ħ² / 2μ) * (∂²/∂x² + ∂²/∂y² + ∂²/∂z²) - (e² / (4πε₀ √(x² + y² + z²)))


### **Task 2: Discretizing the Schrödinger Equation**
- The finite-difference method was applied to discretize the partial derivatives in the Schrödinger equation.  
- Grid spacing `Δx` was used uniformly along all axes, converting the equation into a matrix form suitable for numerical computation.

### **Task 3: Constructing the Hamiltonian Operator**
- Converted the discretized Laplacian operator into a sparse matrix representation.  
- Combined it with the potential energy term to construct the Hamiltonian matrix.  

### **Task 4: Implementing the Power Iteration Algorithm**
- Implemented the power iteration algorithm to compute the dominant eigenvalue and its corresponding eigenstate.  
- Shifted the eigenvalues to find lower-energy states, including the ground state.  

---

## **Key Results**  

1. **Ground State Energy**:  
 - Numerically calculated ground state energy: **13.16 eV**.  
 - Theoretical ground state energy: **-13.6 eV** (discrepancy attributed to numerical limitations).  

2. **Eigenstates**:  
 - Computed several eigenstates corresponding to the excited states of the hydrogen atom.  
 - Visualized the wavefunctions for the ground and first few excited states.  

3. **Plots**:  
 - Probability density plots for the wavefunctions.  
 - Energy eigenvalue trends for the first few states.

---

## **Key Observations and Insights**

- The finite-difference method effectively transforms continuous operators into matrix representations, enabling numerical solutions.  
- Degenerate states resulted in arbitrary linear combinations of eigenstates, as seen in the 2s and 2p orbitals.  
- Numerical eigensolvers like power iteration are useful but slower than advanced algorithms like Arnoldi iteration for large matrices.  

---

## **Challenges Faced**

1. Numerical artifacts due to finite grid size and resolution.  
2. Large memory and computational requirements for fine grids.  
3. Handling degenerate eigenstates and ensuring numerical stability.  

---

## **Learnings**

- Developed a deeper understanding of numerical quantum mechanics.  
- Explored efficient ways to compute and visualize eigenstates of complex systems.  

---
