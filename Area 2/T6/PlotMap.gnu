set xlabel 'x'
set ylabel 'y'
set key left bottom

plot 'mapa_a0.67_b2.50.dat' with dots lc 6 title "a=0,67 b=2,50"
set term pos enh col 'Times, 20'
set output 'mapa_a067_b250.eps'
replot
unset output
set term qt

plot 'mapa_a0.78_b2.50.dat' with dots lc 6 title "a=0,78 b=2,50"
set term pos enh col 'Times, 20'
set output 'mapa_a078_b250.eps'
replot
unset output
set term qt

plot 'mapa_a1.20_b2.50.dat' with dots lc 6 title "a=1,20 b=2,50" 
set term pos enh col 'Times, 20'
set output 'mapa_a120_b250.eps'
replot
unset output
set term qt

plot 'mapa_a1.35_b2.50.dat' with dots lc 6 title "a=1,35 b=2.50"
set term pos enh col 'Times, 20'
set output 'mapa_a135_b250.eps'
replot
unset output
set term qt

plot 'mapa_a0.80_b3.00.dat' with dots lc 6 title "a=0,80 b=3,00"
set term pos enh col 'Times, 20'
set output 'mapa_a080_b300.eps'
replot
unset output
set term qt

plot 'mapa_a1.10_b3.00.dat' with dots lc 6 title "a=1,10 b=3,00"
set term pos enh col 'Times, 20'
set output 'mapa_a110_b300.eps'
replot
unset output
set term qt

plot 'mapa_a2.50_b2.00.dat' with dots lc 6 title "a=2,50 b=2,00"
set term pos enh col 'Times, 20'
set output 'mapa_a250_b200.eps'
replot
unset output
set term qt

plot 'mapa_a3.80_b0.50.dat' with dots lc 6 title "a=3,80 b=0,50"
set term pos enh col 'Times, 20'
set output 'mapa_a380_b050.eps'
replot
unset output
set term qt
