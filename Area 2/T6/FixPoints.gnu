a=0.25
b=0.50
f(x)=(a+b)*x-(a+b)*(a+b)*x*x

set xlabel 'x_{n}'
set ylabel 'x_{n+1}'

set xrange[0:0.25]
plot x, f(x), f(f(x))

a=1.0
replot

set xrange[0:0.27]
a=1.2
replot

set xrange[0:0.26]
a=1.35
replot

set xrange[0:0.263]
a=0.8
b=3.0
replot


set xrange[0:0.5]
a=1.5
b=0.5
replot
