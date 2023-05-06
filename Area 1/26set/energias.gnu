Eo=0.5*0.0*0.0+(1-cos(1.5))*10
set title "{/Symbol q}o = 1.5 rad, {/Symbol q}'o=0.0', g=10.0 m/s^{2}, L=1.0 m, h=0.01"
set logscale y
set xlabel 't'
set ylabel '(E(t)-Eo)/Eo'
set xrange[0:5]
plot 'VelVerlet.dat' u 1:(abs((0.5*$3*$3+(1-cos($2))*10-Eo)/Eo)) w l t 'Verlet', 'RK2.dat' u 1:(abs((0.5*$3*$3+(1-cos($2))*10-Eo)/Eo)) w l t 'RK2', 'RK4.dat' u 1:(abs((0.5*$3*$3+(1-cos($2))*10-Eo)/Eo)) w l t 'RK4'

set term pos enh col 'Times,14'
set out 'PenduloEnergias.eps'
replot
unset out
set term qt