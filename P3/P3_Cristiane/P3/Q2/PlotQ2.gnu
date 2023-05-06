set ylabel 'Integral'
set xlabel 'N'

set logscale x

f(x)=20

plot 'Q2.dat' u 1:2 w lp title '(i)', 'Q2.dat' u 1:3 w lp title '(ii)', 'Q2.dat' u 1:4 w lp title '(iii)', f(x) w l lc rgb 'black' notitle

set term pos enh col 'Times, 18'
set out 'IQ2.eps'
replot
unset out
set term qt

