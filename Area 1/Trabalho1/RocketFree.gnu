u=2600.0
mi=2.8E2
vi=0.0

f(x)=vi+u*log(mi/x)

unset logscale
set xrange[2.8E2:0.7E2]
set ylabel 'Velocidade [m/s]'
set xlabel 'Massa total [10^{4} kg]'

plot 'RocketEulerFree.dat' w l  t 'Euler', 'RocketRK2Free.dat' w l t 'RK2', 'RocketRK4Free.dat' w l t 'RK4', f(x) t 'Solucao'

set term pos enh col 'Times,14'
set out 'Free_Motion.eps'
replot
unset out
set term qt

set ylabel '|v_{num}-v_{exata}|/v_{exata}'
set logscale y
plot 'RocketEulerFree.dat' u 1:(abs($3-$2)) w l t 'Euler', 'RocketRK2Free.dat' u 1:(abs($3-$2)) w l t 'RK2', 'RocketRK4Free.dat' u 1:(abs($3-$2)) w l t 'RK4'

set term pos enh col 'Times,14'
set out 'Free_error.eps'
replot
unset out
set term qt