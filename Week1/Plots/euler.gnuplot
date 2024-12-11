# Set output terminal and file (PNG format)
set terminal png size 1920, 1440
set output "euler.png"

# Set graph title, labels, and grid
set title "Comparison of Euler's Method and Exact Solution" font ",30"
set xlabel "x" font ",24"
set ylabel "y" font ",24"
set grid

#Set margins
set margin 10,10,5,5

# Set x-axis and y-axis ranges and tick intervals
set xrange [0:1]
set xtics 0.05

# Define the exact solution as a function
f(x) = exp(-2*x) * ((x**4 + 4) / 4)

# Plot the Euler method data and the exact solution
plot "euler_0.100000_.txt" using 1:2 with lines lw 2 title "Euler h=0.1", \
     "euler_0.050000_.txt" using 1:2 with lines lw 2 title "Euler h=0.05", \
     "euler_0.025000_.txt" using 1:2 with lines lw 2 title "Euler h=0.025", \
     f(x) with lines lw 4 lc "red" title "Exact Solution"

# Close the output file
set output
