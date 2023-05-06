set xlabel 't'
set ylabel '|E(t)-E_0|/E_0'
set logscale y
set yrange[1E-8:*]
set key below 
set format y "%g"

plot 'Euler-Cromer.dat' u 1:(abs(($6-1.0/12.0)/(1.0/12.0))) ev 100 w l title 'Euler-Cromer','vv.dat' u 1:(abs(($6-1.0/12.0)/(1.0/12.0))) ev 100 w l title 'Velocity-Verlet', 'RK4.dat' u 1:(abs(($6-1.0/12.0)/(1.0/12.0))) ev 100 w l title 'Runge-Kutta 4', 'RK45.dat' u 1:(abs(($6-1.0/12.0)/(1.0/12.0))) ev 100 w l title 'Fehlberg'

set term pos enh col 'Times, 20'
set out 'MetodosE.eps'
replot
unset out
set term qt

unset xlabel
unset ylabel
unset logscale
set xrange[*:*]
set yrange[*:*]
set key  inside right top
unset format y
