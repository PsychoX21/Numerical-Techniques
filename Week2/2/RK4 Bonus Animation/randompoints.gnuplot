set terminal gif animate size 1920, 1440 delay 1
set output 'animation.gif'
set xrange [-5:5]
set yrange [-5:5]
set xlabel 'X'
set ylabel 'Y'

set title 'VDP Oscillator'

do for [row = 0 : 3000] {
    plot for [i=1:50] 'Data/'.i.'.txt' using 2:3 every 1::(row-300>0 ? row-300 : 0)::row title '' with lines, \
         for [i=1:50] 'Data/'.i.'.txt' using 2:3 every 1::row::row title '' with points pt 7 ps 1.5
}