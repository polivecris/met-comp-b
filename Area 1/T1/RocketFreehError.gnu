# Erros em funcao de h
set xrange[*:*]
set key left top
set logscale
set xlabel 'h'
set ylabel 'erro'
set format y "%g"
set title 'm_{i}=2.8E6 kg, m_{f}=0.7E6 kg, v_{0}=0.0 m/s, g=9.8 m/s^{2},u=2600.0 m/s, {/Symbol a}=1.42E4 kg/s'

plot 'dados/EulerFreeherros.dat' u (abs($1)):(abs($4)) w lp t 'Euler', 'dados/RK2Freeherros.dat' u (abs($1)):(abs($4)) w lp t 'RK2', 'dados/RK4Freeherros.dat' u (abs($1)):(abs($4)) w lp t 'RK4'

# Salvar gráfico em imagem
set term pos enh col 'Times,18'
set out 'figuras/Free_herror.eps'
replot
unset out
set term qt
