set xlabel 'x'
set ylabel 'p(x)'

PI=3.141592653589793115997963468544
f(x)=PI/20.0*cos(PI*x/10.0)
plot 'norm_d.dat' w boxes title 'N=100000', f(x) title 'p(x)'

set term pos enh col 'Times, 18'
set out 'NormQ1d.eps'
replot
unset out
set term qt

set xlabel 'r'
set ylabel 'x'
plot 'Q1d.dat' title 'x(r)', f(x) title 'p(x)'

set term pos enh col 'Times, 18'
set out 'cosQ1d.eps'
replot
unset out
set term qt
