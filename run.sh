#!/bin/bash
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
echo "5. Reset for new Meassurement"
echo "6. exit"
echo ""
read -p "(Press Number)" decision

clear

case $decision in
  1)
	echo "//MESA//"
	( exec ./about.sh )
  ;;
  
  2) 	echo "//MESA//" 
	echo "initial setup" 
	echo ""
	echo "//get packages:"
	sudo apt-get install gnuplot gnuplot-x11 cmake build-essentials
	echo "//build Makefiles:"
	cmake .
	echo "//compile:"
	make
  ;;
	
  3)
	echo "//MESA//" 
	echo ""
	read -e -p "Operating mode: (1) no_sharing, (2) false_sharing: " operating_mode_nr
	read -e -p "Insert the minimum amount of threads: " -i "1" threads_start 
	read -e -p "Insert maximum amount of threads: " -i "25"  threads_end 
	read -e -p "Insert the difference (in Threads) between every single measurement: " -i "1"  threads_diff 
	read -e -p "Nr of operations executed per run: " -i "10000"  operations 
	read -e -p "How often (to get a better accuracy):" -i "100" accuracy

	if [ $operating_mode_nr == "1" ]
	   then	
	      operating_mode="no_sharing"
	elif [ $operating_mode_nr == "2" ]   
	   then
	      operating_mode="false_sharing"
	fi

	echo "going do execute: ./BMB -t=$i -op=$operations -m=$operating_mode -o=$operating_mode"
	read
	
	count=0
	max=$((accuracy * (threads_end-threads)/threads_diff))
	for (( i=threads_start; i<=threads_end; i=i+threads_diff ))
	do
	    for(( j=0; j<=accuracy; j++ ))
		do	
	   	./BMB -t=$i -op=$operations -m=$operating_mode -o=$operating_mode
		progress=$((100*count/max))
		let count++
		clear
		echo "//MESA//"
		echo "Progress: $progress%"
		done
	done
	echo "" 
	echo "test successfully executed!"
	echo "($max times executed)"
  ;;

  4)
	echo "//MESA//" 
	echo ""
	gnuplot plot.plt
	echo "graph successfully ploted!"
  ;;

  5)
	echo "//MESA//"
	echo ""
	ls *.dat
	read -p "What file to reset: " $filename
	> $filename
	echo "successfully reseted!"
  ;;

  6)
	exit
  ;;

  *)
	echo "SIKE! thats the wrong number!"
  ;;
esac

echo ""
echo "(Press enter to return to menu)"
read
( exec ./run.sh )

#clear
#echo "//MESA//" 
#echo "Nr. of Threads: $threads_start - $threads_end; Steps: $threads_diff"
#echo ""
