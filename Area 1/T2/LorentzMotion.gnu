unset logscale
set xrange[*:*]

mp=1.6726219E4
me=9.10938356

qp=1.60217662
qe=-1.60217662
Bo=30.0

a=(qe*Bo)/me

f(x)=cos(a*x)/a
g(x)=0.02*x
h(x)=sin(a*x)/a

set xlabel 't'
set ylabel 'x'
set zlabel 'z'

splot 'eRK4.dat' u 1:2:4 w lp title 'Eletron'

set term pos enh col 'Times,18'
set out 'figuras/eLorentz.eps'
replot
unset out
set term qt

Bo=30000.0
a=(qp*Bo)/mp

set xlabel 't'
set ylabel 'x'
set zlabel 'z'

splot 'pRK4.dat' u 1:2:4 w lp lc 2 title 'Proton'

set term pos enh col 'Times,18'
set out 'figuras/pLorentz.eps'
replot
unset out
set term qt
