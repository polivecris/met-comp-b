u=2600.0
mi=2.8E2
vi=0.0
a=1.42E0
g=9.8

f(x)=vi-g/a*(mi-x)+u*log(mi/x)

unset logscale
set xrange[3.0E2:0.5E2]
set key top left
set ylabel 'Velocidade [m/s]'
set xlabel 'Massa total [10^{4} kg]'

set title 'm_{i}=2.8E6 kg, m_{f}=0.7E6 kg, v_{0}=0.0 m/s, g=9.8 m/s^{2},u=2600.0 m/s, {/Symbol a}=1.42E4 kg/s, h=-1'

plot 'dados/RocketEulerGrav.dat' w lp  t 'Euler', 'dados/RocketRK2Grav.dat' w lp t 'RK2', 'dados/RocketRK4Grav.dat' w lp t 'RK4', f(x) t 'Solucao analitica'

set term pos enh col 'Times,18'
set out 'figuras/Grav_Motion.eps'
replot
unset out
set term qt
