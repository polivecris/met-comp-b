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

set format y "%g"
set logscale y
set key right bottom

set xlabel 't'
set ylabel 'erro_z'
plot 'eEuler.dat' u 1:(abs(h(x)-$4)) w l t 'Euler', 'eRK2.dat' u 1:(abs(h(x)-$4)) w l t 'RK2', 'eRK4.dat' u 1:(abs(h(x)-$4)) w l t 'RK4'
set term pos enh col 'Times,18'
set out 'figuras/ez_error.eps'
replot
unset out
set term qt

set xlabel 't'
set ylabel 'erro_y'
plot 'eEuler.dat' u 1:(abs(g(x)-$3)) w l t 'Euler', 'eRK2.dat' u 1:(abs(g(x)-$3)) w l t 'RK2', 'eRK4.dat' u 1:(abs(g(x)-$3)) w l t 'RK4'
set term pos enh col 'Times,18'
set out 'figuras/ey_error.eps'
replot
unset out
set term qt

set xlabel 't'
set ylabel 'erro_x'
plot 'eEuler.dat' u 1:(abs(f(x)-$2)) w l t 'Euler', 'eRK2.dat' u 1:(abs(f(x)-$2)) w l t 'RK2', 'eRK4.dat' u 1:(abs(f(x)-$2)) w l t 'RK4'
set term pos enh col 'Times,18'
set out 'figuras/ex_error.eps'
replot
unset out
set term qt






## Agora para o próton
Bo=30000.0

a=(qp*Bo)/mp

f(x)=cos(a*x)/a
g(x)=0.02*x
h(x)=sin(a*x)/a

set format y "%g"
set logscale y
set key right bottom

set xlabel 't'
set ylabel 'erro_z'
plot 'pEuler.dat' u 1:(abs(h(x)-$4)) w l t 'Euler', 'pRK2.dat' u 1:(abs(h(x)-$4)) w l t 'RK2', 'pRK4.dat' u 1:(abs(h(x)-$4)) w l t 'RK4'
set term pos enh col 'Times,18'
set out 'figuras/pz_error.eps'
replot
unset out
set term qt

set xlabel 't'
set ylabel 'erro_y'
plot 'pEuler.dat' u 1:(abs(g(x)-$3)) w l t 'Euler', 'pRK2.dat' u 1:(abs(g(x)-$3)) w l t 'RK2', 'pRK4.dat' u 1:(abs(g(x)-$3)) w l t 'RK4'
set term pos enh col 'Times,18'
set out 'figuras/py_error.eps'
replot
unset out
set term qt

set xlabel 't'
set ylabel 'erro_x'
plot 'pEuler.dat' u 1:(abs(f(x)-$2)) w l t 'Euler', 'pRK2.dat' u 1:(abs(f(x)-$2)) w l t 'RK2', 'pRK4.dat' u 1:(abs(f(x)-$2)) w l t 'RK4'
set term pos enh col 'Times,18'
set out 'figuras/px_error.eps'
replot
unset out
set term qt
