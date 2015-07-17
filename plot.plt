set view 130, 10, 1, 1
set samples 50, 50
set isosamples 50, 50
set style data linespoints
unset surface
set title "Threads/execution time"
set pm3d implicit at s
set pm3d scansbackward
set terminal png size 1200,900 enhanced font "Helvetica,20"
set output 'output.png'
plot "graph.dat" smooth unique
