unset logscale

mp=1.6726219E4
me=9.10938356

qp=1.60217662
qe=-1.60217662
Bo=30.0

a=(qe*Bo)/me

f(x)=cos(a*x)/a
g(x)=0.02*x
h(x)=sin(a*x)/a


# Erros em funcao de h
set xrange[1E-5:1E-1]
set logscale
set key left
set xlabel 'h'
set ylabel 'erro_{z}'
set format y "%g"

plot 'eEuler_h.dat' u 1:(abs($5)) w lp t 'Euler', 'eEC_h.dat' u 1:(abs($5)) w lp t 'Euler-Cromer', 'eRK2_h.dat' u 1:(abs($5)) w lp t 'RK2', 'eRK4_h.dat' u 1:(abs($5)) w lp t 'RK4'

# Salvar gráfico em imagem
set term pos enh col 'Times,18'
set out 'figuras/h_error.eps'
replot
unset out
set term qt
