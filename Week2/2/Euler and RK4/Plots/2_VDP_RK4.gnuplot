set terminal png size 1920, 1440
set output "rk4_multiplot.png"

set multiplot
set label 1 "Van Der Pol Oscillator (RK4)" at screen 0.5, 0.97 center font ",36"

# Left: y vs x
set size 0.7, 1
set origin 0.0, 0.0
set title "y vs x" font ",24" offset 0, -1.5
set xlabel "x" font ",12"
set ylabel "y" font ",12" offset 2, 0
set margin 10,10,10,10
f(x) = x - x**3/3
plot [-2.2:2.2] f(x) with lines lw 1 title "x-x^3/3", "rungekutta_solution.txt" using 2:3 with lines lw 2 title "VanderPol Oscillator"

# Top right: x vs t
set size 0.3, 0.5
set origin 0.7, 0.5
set title "x vs t" font ",24" offset 0, -1
set xlabel "t" font ",12"
set ylabel "x" font ",12" offset 1, 0
set margin 5,5,5,5
plot "rungekutta_solution.txt" using 1:2 with lines lw 2 title ""

# Bottom right: y vs t
set size 0.3, 0.5
set origin 0.7, 0.0
set title "y vs t" font ",24" offset 0, -1
set xlabel "t" font ",12"
set ylabel "y" font ",12" offset 1, 0
set margin 5,5,5,5
plot "rungekutta_solution.txt" using 1:3 with lines lw 2 title ""

unset multiplot