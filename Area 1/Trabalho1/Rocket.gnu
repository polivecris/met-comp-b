# Erros em funcao de h
set logscale
set xlabel 'h'
set ylabel 'erro'
plot 'Eulerherros.dat' u 1:4 w lp t 'Euler', 'RK2herros.dat' u 1:4 w lp t 'RK2', 'RK4herros.dat' u 1:4 w lp t 'RK4'

# Salvar gráfico em imagem
set term pos enh col 'Times,14'
set out 'herr.eps'
replot
unset out
set term qt

# Parâmetros
vo=0.0
g=9.8
u=-2600.0
a=-1.42E0
mi=2.8E2

# Solucao analítica
f(x)=g/a*(mi-x)-u*log(mi/x)

# Comportamento geral da solução numerica e analitica
plot 'RocketEuler.dat' w l t 'Euler', 'RocketRK2.dat' w l t 'RK2', 'RocketRK4.dat' w l t 'RK4', f(x) t 'Solucao exata'
unset logscale
set xrange[2.8E6:0.7E6]
set xlabel 'Massa total [kg]'
set ylabel 'Velocidade [m/s]'
plot 'RocketEuler.dat' w l t 'Euler', 'RocketRK2.dat' w l t 'RK2', 'RocketRK4.dat' w l t 'RK4', f(x) t 'Solucao exata'

# Salva gráfico em imagem
set term pos enh col 'Times,14'
set out 'Rocket.eps'
replot
unset out
set term qt

# Erros relativos
# Como esse problema nao e uma escolha esperta dá tudo errado :(
set ylabel '|v_{num}-v_{exata}|/v_{exata}'
set logscale y
plot 'RocketEuler.dat' u 1:(abs(f($1)-$2)) w l t 'Euler', 'RocketRK2.dat' u 1:(abs(f($1)-$2)) w l t 'RK2', 'RocketRK4.dat' u 1:(abs(f($1)-$2)) w l t 'RK4'

