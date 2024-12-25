set terminal qt size 1920, 1440

set title "Lorenz Attractor" font ",30"
set view 60, 30
set xlabel "x" font ",20"
set ylabel "y" font ",20"
set zlabel "z" font ",20"
set grid

set margin 10,10,5,5

splot 'rungekutta_1.txt' using 2:3:4 with lines title 'x0=0.1', \
    'rungekutta_2.txt' using 2:3:4 with lines title 'x0=0.10001'

pause -1