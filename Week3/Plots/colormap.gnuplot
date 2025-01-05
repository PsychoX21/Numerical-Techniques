set terminal pngcairo size 1920,1440 enhanced font 'Arial,15'


set output 'poisson_default.png'
set margins 10,10,5,5

set pm3d map
set palette defined ( 0 '#000004', 1 '#1c1044', 2 '#4f127b', 3 '#812581', 4 '#b5367a', 5 '#e55964', 6 '#e56b5d', 7 '#f89441', 8 '#fdc328', 9 '#f0f921' )

set pm3d interpolate 10,10
set title 'Poisson Equation with Dipole Configuration(Default)'
splot 'poisson0.txt' matrix title ""


set output 'poisson_radial.png'
set margins 10,10,5,5

set pm3d map
set palette defined ( 0 '#000004', 1 '#1c1044', 2 '#4f127b', 3 '#812581', 4 '#b5367a', 5 '#e55964', 6 '#e56b5d', 7 '#f89441', 8 '#fdc328', 9 '#f0f921' )

set pm3d interpolate 10,10
set title 'Poisson Equation with Radial Configuration'

splot 'poisson1.txt' matrix title ""


set output 'poisson_gaussian.png'
set margins 10,10,5,5

set pm3d map
set palette defined ( 0 '#000004', 1 '#1c1044', 2 '#4f127b', 3 '#812581', 4 '#b5367a', 5 '#e55964', 6 '#e56b5d', 7 '#f89441', 8 '#fdc328', 9 '#f0f921' )

set pm3d interpolate 10,10
set title 'Poisson Equation with Gaussian Configuration'

splot 'poisson2.txt' matrix title ""

set output 'poisson_sinusoidal.png'
set margins 10,10,5,5

set pm3d map
set palette defined ( 0 '#000004', 1 '#1c1044', 2 '#4f127b', 3 '#812581', 4 '#b5367a', 5 '#e55964', 6 '#e56b5d', 7 '#f89441', 8 '#fdc328', 9 '#f0f921' )

set pm3d interpolate 10,10
set title 'Poisson Equation with Sinusoidal Configuration'

splot 'poisson3.txt' matrix title ""

set output 'poisson_chessboard.png'
set margins 10,10,5,5

set pm3d map
set palette defined ( 0 '#000004', 1 '#1c1044', 2 '#4f127b', 3 '#812581', 4 '#b5367a', 5 '#e55964', 6 '#e56b5d', 7 '#f89441', 8 '#fdc328', 9 '#f0f921' )

set pm3d interpolate 10,10
set title 'Poisson Equation with Chessboard Configuration'

splot 'poisson4.txt' matrix title ""

set output 'poission_spiral.png'
set margins 10,10,5,5

set pm3d map
set palette defined ( 0 '#000004', 1 '#1c1044', 2 '#4f127b', 3 '#812581', 4 '#b5367a', 5 '#e55964', 6 '#e56b5d', 7 '#f89441', 8 '#fdc328', 9 '#f0f921' )

set pm3d interpolate 10,10
set title 'Poisson Equation with Spiral Configuration'

splot 'poisson5.txt' matrix title ""

set output 'poisson_starburst.png'
set margins 10,10,5,5

set pm3d map
set palette defined ( 0 '#000004', 1 '#1c1044', 2 '#4f127b', 3 '#812581', 4 '#b5367a', 5 '#e55964', 6 '#e56b5d', 7 '#f89441', 8 '#fdc328', 9 '#f0f921' )

set pm3d interpolate 10,10
set title 'Poisson Equation with Starburst Configuration'

splot 'poisson6.txt' matrix title ""

unset output