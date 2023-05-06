set key left

set ylabel 'log(|sol_{exata}-sol_{num}|)'
set xlabel 'log(h)'

a=-8.790295980472e-01
b=2.00
f(x)=a+b*x
fit f(x) 'herros.dat' u 1:2 via b

unset logscale

plot 'herros.dat' u 1:2 lt 7 lc rgb 'web-blue' lw 10 title 'Ponto Medio', f(x) lc rgb 'black' lw 2 dt 2 title 'Ajuste'

set term pos enh col 'Times, 18'
set out 'h_erros_mid.eps'
replot
unset out
set term qt


fit f(x) 'herros.dat' u 1:3 via b

plot 'herros.dat' u 1:3 lt 5 lc rgb 'light-red' lw 10 title 'Euler Modificado', f(x) lc rgb 'black' lw 2 dt 2 title 'Ajuste'

set term pos enh col 'Times, 18'
set out 'h_erros_eul.eps'
replot
unset out
set term qt

plot 'resultados.dat' u 1:(abs($4-$2)) w lp lc rgb 'web-blue' title 'erro_{PM}', 'resultados.dat' u 1:(abs($4-$3)) w lp lc rgb 'light-red' title 'erro_{EM}'

set term pos enh col 'Times, 18'
set out 'erros.eps'
replot
unset out
set term qt
