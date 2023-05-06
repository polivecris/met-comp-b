set xlabel 'x' 
set ylabel 'y'
plot 'caos-1.dat' u 2:3 w l ls 1 notitle, 'caos0.dat' u 2:3 w l ls 2 notitle, 'caos1.dat' u 2:3  w l ls 28 notitle, 'caos-1.dat' u 2:3 every 5999 w p ls 1 title 'E-{/Symbol d}', 'caos0.dat' u 2:3 every 5999 w p ls 2 title 'E', 'caos1.dat' u 2:3 every 5999 w p ls 28 title 'E+{/Symbol d}'

set term pos enh col 'Times, 20'
set out 'Henon-Heiles_caos.eps'
replot
unset out
set term qt

set terminal gif animate delay 1.0E-15
set output "Henon-Heiles_animacao.gif"

set xrange[-0.8:0.8]
set yrange[-0.6:1.0]
set xlabel 'x'
set ylabel 'y'

do for [ii=1:6000:15] {
    plot 'caos-1.dat' u 2:3 every ::1::ii w l ls 1 notitle, \
         'caos-1.dat' u 2:3 every ::ii::ii w p ls 1 title 'E-{/Symbol d}', \
	 'caos0.dat' u 2:3 every ::1::ii w l ls 2 notitle, \
         'caos0.dat' u 2:3 every ::ii::ii w p ls 2 title 'E', \
	 'caos1.dat' u 2:3 every ::1::ii w l ls 28 notitle, \
         'caos1.dat' u 2:3 every ::ii::ii w p ls 28 title 'E+{/Symbol d}', 
}

set terminal qt

unset xlabel
unset ylabel 
set xrange[*:*]
set yrange[*:*]
