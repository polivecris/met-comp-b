u=2600.0
mi=2.8E2
vi=0.0
a=1.42E0
g=9.8

set logscale y
set format y "%g"
set xrange[3.0E2:0.5E2]
set ylabel 'Velocidade [m/s]'
set xlabel 'Massa total [10^{4} kg]'

set key top left
set title 'm_{i}=2.8E6 kg, m_{f}=0.7E6 kg, v_{0}=0.0 m/s, g=9.8 m/s^{2},u=2600.0 m/s, {/Symbol a}=1.42E4 kg/s, h=-1'

plot 'dados/RocketRK4Free.dat' w l t 'Free', 'dados/RocketRK4Grav.dat' w l t 'Grav','dados/RocketRK4Res0.00e+00.dat' w l t '{/Symbol g}=0.0','dados/RocketRK4Res1.00e-06.dat' w l t '{/Symbol g}=10^{-6}','dados/RocketRK4Res1.00e-05.dat' w l t '{/Symbol g}=10^{-5}','dados/RocketRK4Res1.00e-04.dat' w l t '{/Symbol g}=10^{-4}','dados/RocketRK4Res1.00e-03.dat' w l t '{/Symbol g}=10^{-3}','dados/RocketRK4Res1.00e-02.dat' w l t '{/Symbol g}=10^{-2}','dados/RocketRK4Res1.00e-01.dat' w l t '{/Symbol g}=10^{-1}'

set term pos enh col 'Times, 18'
set out 'figuras/RocketAll.eps'
replot
unset out
set term qt
