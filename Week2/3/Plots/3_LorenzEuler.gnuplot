set terminal qt size 1920, 1440

set title "Lorenz Attractor Euler Plot" font ",30"
set view 60, 30
set xlabel "x" font ",20"
set ylabel "y" font ",20"
set zlabel "z" font ",20"
set grid

set margin 10,10,5,5

splot 'euler_solution.txt' using 2:3:4 with lines title '3D Trajectory'

pause -1