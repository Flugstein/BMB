#!/bin/bash
clear
threads_start=
threads_diff=
threads_end=
operations=
accuracy=
decision=

echo "// Multithreading Evironment System Analyser //"
echo "Bash version ${BASH_VERSION}..."
echo "-"
echo "Good morning and welcome to the Black MESA Transit System."
echo "This automated train is provided for the security and convenience of the Black Mesa Research Facility personnel."
echo ""
echo "1. about ..."
echo "2. Initial Start"
echo "3. Run Test"
echo "4. Plot Graph"
echo "(Press Number)"
read decision
 
echo "Insert the minimum amount of threads:"
read threads_start
echo ""
echo "Insert maximum amount of threads:"
read threads_end
echo ""
echo "Insert the difference (in Threads) between every single measurement:"
read threads_diff
echo ""
echo "Nr of operations executed per run: (NOT WORKING ATM)"
read operations
echo ""
echo "How often (to get a better accuracy):"
read accuracy
clear
echo "//MESA// Nr. of Threads: $threads_start - $threads_end; Steps: $threads_diff"

for (( i=threads_start; i<=threads_end; i=i+threads_diff ))
do
    for(( j=0; j<=accuracy; j++ ))
	do	
   	./BMB -t=$i
	done
done
