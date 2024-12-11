# Set output terminal and file (PNG format)
set terminal png size 1920, 1440
set output "rk4.png"

# Set graph title, labels, and grid
set title "Comparison of Runge Kutta's Method and Exact Solution" font ",30"
set xlabel "x" font ",24"
set ylabel "y" font ",24"
set grid

#Set margins
set margin 10,10,5,5

# Set x-axis and y-axis ranges and tick intervals
set xrange [0:1]
set xtics 0.1

# Define the exact solution as a function
f(x) = exp(-2*x) * ((x**4 + 4) / 4)

# Plot the Runge Kutta method data and the exact solution
plot "rungekutta.txt" using 1:2 with lines lw 2 lc "blue" title "Runge Kutta (stepsize=0.1)", \
     f(x) with lines lw 2 lc "red" title "Exact Solution"

# Close the output file
set output
