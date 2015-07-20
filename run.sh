#!/bin/bash
threads_start=
threads_diff=
threads_end=
operations=
accuracy=
decision=
progress=

goto main

main:
clear
echo "// Multithreading Evironment System Analyser //"
echo "       Bash version ${BASH_VERSION}..."
echo ""
echo "Good morning and welcome to the Black MESA Transit System."
echo "This automated train is provided for the security and convenience of the Black Mesa Research Facility personnel."
echo ""
echo "1. about ..."
echo "2. Initial Start"
echo "3. Run Test"
echo "4. Plot Graph"
echo "5. exit"
echo "(Press Number)"
read decision

clear

case $decision in
  1)
	echo "//MESA//"
	( exec ./about.sh )
  ;;
  
  2) 	echo "//MESA//" 
	echo "initial setup" 
	echo ""
	sudo apt-get install gnuplot gnuplot-x11 cmake build-essentials
	cmake .
	make
  ;;
	
  3)
	echo "//MESA//" 
	echo ""
	echo "Insert the minimum amount of threads:"
	read threads_start
	echo ""
	echo "Insert maximum amount of threads:"
	read threads_end
	echo ""
	echo "Insert the difference (in Threads) between every single measurement:"
	read threads_diff
	echo ""
	echo "Nr of operations executed per run: (NOT WORKING ATM)(10000 by default)"
	read operations
	echo ""
	echo "How often (to get a better accuracy):"
	read accuracy

	count=0
	max=$((accuracy * (threads_end-threads)/threads_diff))
	for (( i=threads_start; i<=threads_end; i=i+threads_diff ))
	do
	    for(( j=0; j<=accuracy; j++ ))
		do	
	   	./BMB -t=$i	
		progress=$((100*count/max))
		let count++
		clear
		echo "//MESA//"
		echo "Progress: $progress%"
		done
	done
	echo "//MESA//" 
	echo "test successfully executed!"
  ;;

  4)
	echo "//MESA//" 
	echo ""
	gnuplot plot.plt
	echo "graph successfully ploted!"
  ;;

  5)
	exit
  ;;
esac

echo ""
echo "(Press any key to return to menu)"
read
( exec ./run.sh )

#clear
#echo "//MESA//" 
#echo "Nr. of Threads: $threads_start - $threads_end; Steps: $threads_diff"
#echo ""
