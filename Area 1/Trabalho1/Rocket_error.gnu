# Parâmetros
vo=0.0
g=9.8
u=-2600.0
a=-1.42E0
mi=2.8E2

# Solucao analítica
f(x)=g/a*(mi-x)-u*log(mi/x)
unset logscale
set xrange[2.8E6:0.7E6]
set xlabel 'Massa total [kg]'

# Erros relativos
# Como esse problema nao e uma escolha esperta dá tudo errado :(
set ylabel '|v_{num}-v_{exata}|/v_{exata}'
plot 'RocketEuler.dat' u 1:(abs(f($1)-$2)) w l t 'Euler', 'RocketRK2.dat' u 1:(abs(f($1)-$2)) w l t 'RK2', 'RocketRK4.dat' u 1:(abs(f($1)-$2)) w l t 'RK4'
