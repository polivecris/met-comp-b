set xlabel 'x'
set ylabel 'freq(x)'
plot 'hist0.dat' w boxes title 'N=100','hist1.dat' w boxes title 'N=1000', 'hist2.dat' w boxes title 'N=10000', 'hist3.dat' w boxes title 'N=100000', 'hist4.dat' w boxes title 'N=1000000'

set term pos enh col 'Times, 18'
set out 'HistQ1.eps'
replot
unset out
set term qt

PI=3.141592653589793115997963468544
f(x)=PI/20.0*cos(PI*x/10.0)

plot 'norm0.dat' w boxes title 'N=100','norm1.dat' w boxes title 'N=1000', 'norm2.dat' w boxes title 'N=10000', 'norm3.dat' w boxes title 'N=100000', 'norm4.dat' w boxes title 'N=1000000', f(x) title 'p(x)'

set ylabel 'p(x)'
set term pos enh col 'Times, 18'
set out 'NormQ1.eps'
replot
unset out
set term qt
