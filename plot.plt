set title "Threads/execution time"
set xlabel "Threads"
set ylabel "Operations/sec"

set xrange [1:]

set terminal png size 1200,900 enhanced font "Helvetica,20"
set output 'output.png'

set view 130, 10, 1, 1
set samples 50, 50
set isosamples 50, 50
set style data linespoints
unset surface

set pm3d implicit at s
set pm3d scansbackward

plot 'no_sharing.dat' smooth unique, 'false_sharing.dat' smooth unique
