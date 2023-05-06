set xlabel 'a'
set ylabel 'Variancia'

plot 'minvarQ5.dat' w l title 'Var(a)'
f(x)=a*x**2+b*x+c 
fit f(x) 'minvarQ5.dat' via a,b,c
replot f(x) notitle

set term pos enh col 'Times, 18'
set out 'VarQ5.eps'
replot
unset out
set term qt


set xlabel 'Repeticao'
set ylabel 'Integral'

f(x)=1.581187970847728
plot 'Q5b.dat' u 1:2 w l title 'Importancia', 'Q5b.dat' u 1:3 w l title 'Uniforme', f(x) lc rgb 'black' title 'Analitico'

set term pos enh col 'Times, 18'
set out 'Q5comp.eps'
replot
unset out
set term qt

