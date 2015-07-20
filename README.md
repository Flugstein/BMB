# *MESA
Multithreading Evironment System Analyser

If you dont want to go into detail: use the `run.sh` script for easy starting:

	./run.sh

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

	./BMB -threads=10 -operations=100 -mode=no_sharing -output_name=name

or:

	./BMB -t=10 -op=100 -m=false_sharing -o=name


# GNUPlot

plot and save graph with:

	gnuplot plot.plt

Graph will be stored in `BMB/` as "output.png"

clear data file when you want to run a new measurement:

	> graph.dat



*black
