set terminal pngcairo size 1920,1440 enhanced font 'Arial,15'
set margins 10,10,5,5
set pm3d map
set pm3d interpolate 5,5
set palette defined ( 0 '#000004', 1 '#1c1044', 2 '#4f127b', 3 '#812581', 4 '#b5367a', 5 '#e55964', 6 '#e56b5d', 7 '#f89441', 8 '#fdc328', 9 '#f0f921' )

set output 'poisson_default.png'
set title 'Poisson Equation with Dipole Configuration(Default)'
splot 'poisson0.txt' matrix title ""

set output 'poisson_gaussian.png'
set title 'Poisson Equation with Gaussian Configuration'
splot 'poisson1.txt' matrix title ""

set output 'poisson_chess.png'
set title 'Poisson Equation with Chess Configuration'
splot 'poisson2.txt' matrix title ""

set output 'poisson_spiral.png'
set title 'Poisson Equation with Spiral Configuration'
splot 'poisson3.txt' matrix title ""

set output 'poisson_magnetic_dipole.png'
set title 'Poisson Equation with Magnetic Dipole Configuration'
splot 'poisson4.txt' matrix title ""

set output 'poisson_vortex.png'
set title 'Poisson Equation with Vortex Configuration'
splot 'poisson5.txt' matrix title ""

set output 'poisson_sinusoidal_ripple.png'
set title 'Poisson Equation with Sinusoidal Ripple Configuration'
splot 'poisson6.txt' matrix title ""

unset output