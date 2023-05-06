set xlabel 'Parametro a'
set ylabel 'Variancia'

plot 'Q5.dat' w l title 'Var(a)'
set term pos enh col 'Times, 18'
set out 'VarQ5.eps'
replot
unset out
set term qt

set xrange[0.0:1.5]
set yrange[*:*]
f(x)=c*x**2+b*x+a 
fit f(x) 'Q5.dat' via a,b,c
plot 'Q5.dat' title 'Var(a)', f(x) title 'Var_{min}: a=0,75114'

set term pos enh col 'Times, 18'
set out 'VarMinQ5.eps'
replot
unset out
set term qt

set xrange[*:*]
set yrange[*:*]

set xlabel 'Repeticao'
set ylabel 'Integral'

f(x)=1.581187970847728
plot 'Q5b.dat' u 1:2 w l title 'Importancia', 'Q5b.dat' u 1:3 w l title 'Uniforme', f(x) lc rgb 'black' title 'Analitico'

set term pos enh col 'Times, 18'
set out 'Q5comp.eps'
replot
unset out
set term qt

