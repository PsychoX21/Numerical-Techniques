set terminal png size 1920, 1440
set output "VDP.png"

set title "Van Der Pol Oscillator" font ",30"

set xlabel "x" font ",20"
set ylabel "y" font ",20"

set margin 10,10,7,7
set grid

plot "euler_solution.txt" using 2:3 with lines lw 2 title "Euler", "rungekutta_solution.txt" using 2:3 with lines lw 2 title "RK4"

unset output