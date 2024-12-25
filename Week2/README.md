# Week 2: Numerical Techniques in Physics
Welcome to the Week 2 report for Numerical Techniques in Physics. This README provides a summary of the problems tackled, methods implemented, and results obtained during the second week of the project.

---

## Problem 1: Solving Second-Order ODEs
### Task:
Solve the second-order ODE:
𝑦′′+4𝑦′+3𝑦=sin(𝑥)+2cos(𝑥)

with initial conditions 
𝑦(0)=1 and 𝑦′(0)=−1

using:

*Euler Method: Compare results for step sizes 
h=0.1 and h=0.01.

*RK4 Method: Use a step size 
ℎ=0.1.

Plot the solutions from both methods and compare them with the exact solution.

### Method Overview:
Transform the second-order ODE into a system of first-order ODEs.
Let 𝑦1=𝑦 and 𝑦2=𝑦′ , giving:
𝑦1′=𝑦2
𝑦2′=sin(𝑥)+2cos(𝑥)−4𝑦2−3𝑦1
​
Apply numerical methods (Euler and RK4) to solve the system.

### Results:
Euler Method: Larger step sizes caused noticeable divergence from the exact solution. Smaller step sizes provided better accuracy.
RK4 Method: Showed excellent agreement with the exact solution even at h=0.1.

### Key Observations:
RK4 consistently outperformed the Euler method in accuracy and stability.
The plots clearly demonstrated how smaller step sizes improve the Euler method's precision.

---

## Problem 2: Van der Pol Oscillator

### Task:
Implement the Van der Pol Oscillator equations for μ=7:

𝑥˙=𝜇(𝑥−𝑥3/3−𝑦)
𝑦˙=𝑥/𝜇​
 
using:
Euler Method with h=0.1.
RK4 Method with h=0.1.

Generate the following plots:

y vs. 𝑥
x vs. t
y vs. t

Additionally, create an animation of the system's evolution with varying 
μ from 0.1 to 4.

### Method Overview:
Discretize the equations for both methods.
Use the equations to trace trajectories and visualize the system.

### Results:
Euler's method captured the general trend but struggled with stability for larger time intervals.
RK4 provided smoother trajectories and was used for animations.

Bonus Animation: Created an animation showing how initial conditions are attracted to stable orbits and how varying μ changes the dynamics.

### Key Observations:
RK4's stability made it the preferred method for modeling this oscillator.
The y=x−x3/3 curve on the plot showed the system's limiting cycle.

---

## Problem 3: Lorenz Attractor
### Task:
Simulate the Lorenz Attractor system:
𝑥˙=𝜎(𝑦−𝑥)
𝑦˙=𝑥(𝜌−𝑧)−𝑦
𝑧˙=𝑥𝑦−𝛽𝑧

using:
Euler Method.
RK4 Method.

Parameters:
Standard parameters: 
𝜌=28,
𝜎=10,
𝛽=8/3

Alternate cases: 
𝜌=14 and 𝜌=99.96

Additional Tasks:
Show the 3D evolution of two trajectories starting from initial conditions differing by 
10^(−5) in the x-coordinate.

Highlight the sensitivity of the system to initial conditions.

### Method Overview:
Numerically integrate the Lorenz equations for the given parameters and initial conditions.
Generate 3D phase-space plots for all scenarios.

### Results:
The RK4 method provided smoother and more accurate trajectories compared to Euler.
The trajectories starting from slightly different initial conditions diverged rapidly, demonstrating the chaotic nature of the system.
