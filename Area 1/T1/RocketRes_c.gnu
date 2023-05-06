# Gráfico de Velocidade por Massa foguete sob ação da gravidade e força de arrasto

set xrange[3.0E2:0.5E2]
set logscale y

set xlabel 'Massa total [10^{4} kg]'
set ylabel 'Velocidade [m/s]'

set key left top

set title 'm_{i}=2.8E6 kg, m_{f}=0.7E6 kg, v_{0}=0.0 m/s, g=9.8 m/s^{2},u=2600.0 m/s, {/Symbol a}=1.42E4 kg/s, h=-1'


# Pelo método de Euler
plot 'dados/RocketEulerRes0.00e+00.dat' w l t '{/Symbol g}=0.0', 'dados/RocketEulerRes1.00e-01.dat' w l t '{/Symbol g}=10^{-1}','dados/RocketEulerRes1.00e-02.dat' w l t '{/Symbol g}=10^{-2}', 'dados/RocketEulerRes1.00e-03.dat' w l t '{/Symbol g}=10^{-3}', 'dados/RocketEulerRes1.00e-04.dat' w l t '{/Symbol g}=10^{-4}', 'dados/RocketEulerRes1.00e-05.dat' w l t '{/Symbol g}=10^{-5}', 'dados/RocketEulerRes1.00e-06.dat' w l t '{/Symbol g}=10^{-6}'

set term pos enh col 'Times, 18'
set out 'figuras/RocketEulerRes.eps'
replot
unset out
set term qt

# Pelo método de RK2
plot 'dados/RocketRK2Res0.00e+00.dat' w l t '{/Symbol g}=0.0', 'dados/RocketRK2Res1.00e-01.dat' w l t '{/Symbol g}=10^{-1}','dados/RocketRK2Res1.00e-02.dat' w l t '{/Symbol g}=10^{-2}', 'dados/RocketRK2Res1.00e-03.dat' w l t '{/Symbol g}=10^{-3}', 'dados/RocketRK2Res1.00e-04.dat' w l t '{/Symbol g}=10^{-4}', 'dados/RocketRK2Res1.00e-05.dat' w l t '{/Symbol g}=10^{-5}', 'dados/RocketRK2Res1.00e-06.dat' w l t '{/Symbol g}=10^{-6}'

set term pos enh col 'Times, 18'
set out 'figuras/RocketRK2Res.eps'
replot
unset out
set term qt

# Pelo método de RK4
plot 'dados/RocketRK4Res0.00e+00.dat' w l t '{/Symbol g}=0.0', 'dados/RocketRK4Res1.00e-01.dat' w l t '{/Symbol g}=10^{-1}','dados/RocketRK4Res1.00e-02.dat' w l t '{/Symbol g}=10^{-2}', 'dados/RocketRK4Res1.00e-03.dat' w l t '{/Symbol g}=10^{-3}', 'dados/RocketRK4Res1.00e-04.dat' w l t '{/Symbol g}=10^{-4}', 'dados/RocketRK4Res1.00e-05.dat' w l t '{/Symbol g}=10^{-5}', 'dados/RocketRK4Res1.00e-06.dat' w l t '{/Symbol g}=10^{-6}'

set term pos enh col 'Times, 18'
set out 'figuras/RocketRK4Res.eps'
replot
unset out
set term qt
