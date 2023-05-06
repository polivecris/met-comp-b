f(x)=0
set lmargin at screen 0.15
set rmargin at screen 0.95
set xtics 0.5
set key left bottom

set size 1.0,1.0
set term pos enh col 'Times, 20'
set output 'lyapunov_a00_b05.eps'
set multiplot layout 2,1 rowsfirst
set offset 0,0,graph 0.05, graph 0.05
set size 1.0,0.5
set tmargin 1
set bmargin 0
set xrange[0:3.864]
set format x ""
set ytics -3.0,0.6,0.6
set ylabel 'Expoente'
unset xlabel
plot 'lyapunov_a0.00_b0.50.dat' w l lc 6 notitle, f(x) lc rgb 'black' notitle
set xtics nomirror
set size 1.0,0.5
set tmargin 0
set bmargin 3
set format x "%g"
set ytics -0.05,0.05,0.25
set ylabel 'x'
set xlabel 'a'
plot 'bifurcac_a0.00_b0.50.dat' w d lc 6 title 'b=0,5'
unset multiplot
unset output
set term qt

set size 1.0,1.0
set term pos enh col 'Times, 20'
set output 'lyapunov_a00_b20.eps'
set multiplot layout 2,1 rowsfirst
set offset 0,0,graph 0.05, graph 0.05
set size 1.0,0.5
set tmargin 1
set bmargin 0
set xrange[8.0e-03:2.64]
set format x ""
set ytics -2.5,0.5,0.0
set ylabel 'Expoente'
unset xlabel
plot 'lyapunov_a0.00_b2.00.dat' w l lc 6 notitle, f(x) lc rgb 'black' notitle
set xtics nomirror
set size 1.0,0.5
set tmargin 0 
set bmargin 3 
set format x "%g"
set ytics -0.2,0.1,0.3
set ylabel 'x'
set xlabel 'a'
plot 'bifurcac_a0.00_b2.00.dat' w d lc 6 title 'b=2,0'
unset multiplot
unset output
set term qt

set size 1.0,1.0
set term pos enh col 'Times, 20'
set output 'lyapunov_a00_b25.eps'
set multiplot layout 2,1 rowsfirst
set offset 0,0,graph 0.05, graph 0.05
set size 1.0,0.5
set tmargin 1
set bmargin 0
set xrange[0:2.16]
set format x ""
set ytics -0.45,0.15,0.45
set ylabel 'Expoente'
unset xlabel
plot 'lyapunov_a0.00_b2.50.dat' w l lc 6 notitle, f(x) lc rgb 'black' notitle
set xtics nomirror
set size 1.0,0.5
set tmargin 0 
set bmargin 3 
set format x "%g"
set ytics -0.2,0.1,0.2
set ylabel 'x'
set xlabel 'a'
plot 'bifurcac_a0.00_b2.50.dat' w d lc 6 title 'b=2,5'
unset multiplot
unset output
set term qt

set size 1.0,1.0
set term pos enh col 'Times, 20'
set output 'lyapunov_a05_b30.eps'
set multiplot layout 2,1 rowsfirst
set offset 0,0,graph 0.05, graph 0.05
set size 1.0,0.5
set tmargin 1
set bmargin 0
set xrange[-0.5:1.656]
set format x ""
set ytics -0.2,0.1,0.3
set ylabel 'Expoente'
unset xlabel
plot 'lyapunov_a-0.50_b3.00.dat' w l lc 6 notitle, f(x) lc rgb 'black' notitle
set xtics nomirror
set size 1.0,0.5
set tmargin 0 
set bmargin 3 
set format x "%g"
set ytics -0.2,0.1,0.2
set ylabel 'x'
set xlabel 'a'
plot 'bifurcac_a-0.50_b3.00.dat' w d lc 6 title 'b=3,0'
unset multiplot
unset output
set term qt
