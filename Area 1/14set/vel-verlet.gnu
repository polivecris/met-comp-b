set xlabel 't'
set ylabel 'x(t)'
set title "{/Symbol q}o=3.0 rad, {/Symbol q}'o=0.0, g=10.0 m/s^{2}, L=1.0 m, h=0.1"
plot 'vel-verlet4.dat' u 1:2 w l t 'Posicao', 'vel-verlet4.dat' u 1:3 w l t 'Velocidade'
#'MHSeuler.dat' u ($1):(($3*$3+3*$2*$2-Eo)/Eo) w l t 'Euler', 'MHSeuler-cromer.dat' u ($1):(($3*$3+3*$2*$2-Eo)/Eo) w l t 'Euler-Cromer'

set term pos enh col 'Times,14'
set out 'PenduloVelVerlet4.eps'
replot
unset out
set term qt