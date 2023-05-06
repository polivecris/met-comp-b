# Erros em funcao de h
set xlabel 'h'
set ylabel 'erro'
plot 'Eulerherros.dat' u 1:4 w lp t 'Euler', 'RK2herros.dat' u 1:4 w lp t 'RK2', 'RK4herros.dat' u 1:4 w lp t 'RK4'

# Salvar gráfico em imagem
set term pos enh col 'Times,14'
set out 'herror.eps'
replot
unset out
set term qt
