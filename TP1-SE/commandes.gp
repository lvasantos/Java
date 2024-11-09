set samples 500
set title 'Sinus Cardinal'
set xlabel 'x'
set ylabel 'sin(x)/x'
set key font 'Times New Roman, 12'
set xrange [-120.000000:120.000000]
set border
set grid
plot sin(x)/x
