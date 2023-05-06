set xlabel 'y'
set ylabel  '~y{.8.}'

set xrange[-0.4:0.4]
plot 'poincare0.04167.dat' u 3:5 w dots title 'E=1/24}
set term pos enh col 'Times, 20'
set out 'P004167.eps'
replot
unset out
set term qt

set xrange[-0.5:0.6]
plot 'poincare0.08333.dat' u 3:5 w dots title 'E=1/12'
set term pos enh col 'Times, 20'
set out 'P008333.eps'
replot
unset out
set term qt

set xrange[-0.6:0.8]
plot 'poincare0.12500.dat' u 3:5 w dots title 'E=1/8'
set term pos enh col 'Times, 20'
set out 'P012500.eps'
replot
unset out
set term qt

set xrange[-0.6:1.2]
plot 'poincare0.16667.dat' u 3:5 w dots title 'E=1/6'
set term pos enh col 'Times, 20'
set out 'P016667.eps'
replot
unset out
set term qt

unset xlabel
unset ylabel
set xrange[*:*]
set yrange[*:*]
