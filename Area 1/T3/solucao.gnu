set key left

set xlabel 't'
set ylabel 'y(t)'

f(x)=exp(-x)+x

plot 'resultados.dat' u 1:2 lt 7 lc rgb 'web-blue' lw 10 title 'Ponto Medio', f(x) lc rgb 'black' lw 2 dt 2 title 'Solucao exata'

set term pos enh col 'Times, 18'
set out 'solucao_mid.eps'
replot
unset out
set term qt

plot 'resultados.dat' u 1:3 lt 5 lc rgb 'light-red' lw 10 title 'Euler Modificado', f(x) lc rgb 'black' lw 2 dt 2 title 'Solucao exata'

set term pos enh col 'Times, 18'
set out 'solucao_eul.eps'
replot
unset out
set term qt


set ylabel 'y_{PM}(t)-y_{EM}(t)
f(x)=0
plot 'resultados.dat' u 1:($2-$3) lt 3 lc rgb 'web-green' lw 3 title 'PM - EM', f(x) lc rgb 'black' lw 2 dt 2 title 'y=0'

set term pos enh col 'Times, 18'
set out 'mid_eul.eps'
replot
unset out
set term qt
