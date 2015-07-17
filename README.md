# BMB
Basic Multithreading Benchmark

you will need the following programms/frameworks:
* gcc
* cmake
* gnuplot

how to install:

	sudo apt-get install gnuplot gnuplot-x11 cmake build-essentials

Compile:

	cmake .
	make

Example how to execute a test: 

	./BMB -threads=10

or:

	./BMB -t=10


# GNUPlot

plot and save graph with:

	gnuplot plot.plt

Graph will be stored in `BMB/` as "output.png"

clear data file when you want to run a new measurement:

	> graph.dat
