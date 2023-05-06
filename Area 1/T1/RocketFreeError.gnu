set ylabel '|v_{num}-v_{exata}| [m/s]'
set xlabel 'Massa total [10^{4} kg]'
set format y "%g"
set logscale y
set xrange[3.0E2:0.5E2]
set key right bottom

set title 'm_{i}=2.8E6 kg, m_{f}=0.7E6 kg, v_{0}=0.0 m/s, g=9.8 m/s^{2},u=2600.0 m/s, {/Symbol a}=1.42E4 kg/s, h=-1'
plot 'dados/RocketEulerFree.dat' u 1:(abs($3-$2)) w l t 'Euler', 'dados/RocketRK2Free.dat' u 1:(abs($3-$2)) w l t 'RK2', 'dados/RocketRK4Free.dat' u 1:(abs($3-$2)) w l t 'RK4'

set term pos enh col 'Times,18'
set out 'figuras/Free_error.eps'
replot
unset out
set term qt
