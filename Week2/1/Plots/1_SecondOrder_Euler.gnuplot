set terminal png size 1920, 1440
set output "1euler.png"

set title "Comparison of Euler's Method and Exact Solution" font ",36"
set xlabel "x" font ",24"
set ylabel "y" font ",24"
set grid

set margin 10,10,5,5

set xrange [0:10]
set xtics 0.5

f(x) = 3 * exp(-x) /4 + exp(-3*x) / 4 + sin(x) / 2

plot "euler_0.1_.txt" using 1:2 with lines lw 2 title "Euler (h=0.1)" ,\
    "euler_0.01_.txt" using 1:2 with lines lw 2 title "Euler (h=0.01)" ,\
    f(x) with lines lw 2 lc "red" title "Exact Solution"

unset output