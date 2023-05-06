set xrange[-500:500]
set xlabel 'x'
set ylabel 'freq(x)'

plot 'Q3100.dat' w boxes title '100 passo', 'Q31000.dat' w boxes title '1000 passos', 'Q310000.dat' w boxes title '10000 passos'

set term pos enh col 'Times,18'
set out 'histQ3.eps'
replot
unset out
set term qt

f(x)=b*x**2+log(a)

set xrange[*:*]
set yrange[*:*]
plot 'Q3100.dat' u 1:(log($2)) w boxes title '100 passo' 
fit f(x) 'Q3100.dat' u 1:(log($2)) via a,b
replot f(x) notitle lc 1

set term pos enh col 'Times, 18'
set out 'log100.eps'
replot
unset out
set term qt

set xrange[-150:150]
set yrange[*:*]
plot 'Q31000.dat' u 1:(log($2)) w boxes title '1000 passos' lc 2
fit f(x) 'Q31000.dat' u 1:(log($2)) via a,b
replot f(x) notitle lc 2

set term pos enh col 'Times, 18'
set out 'log1000.eps'
replot
unset out
set term qt

set xrange[-500:500]
set yrange[*:*]
plot 'Q310000.dat' u 1:(log($2)) w boxes title '10000 passos' lc 3
fit f(x) 'Q310000.dat' u 1:(log($2)) via a,b
replot f(x) notitle lc 3

set term pos enh col 'Times, 18'
set out 'log10000.eps'
replot
unset out
set term qt

