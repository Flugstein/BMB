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

Example: 
	./BMB -threads=10
or:
	./BMB -t=10


# GNUPlot

display/plot graph with:

	gnuplot plot.plt

clear data file:

	> graph.dat
