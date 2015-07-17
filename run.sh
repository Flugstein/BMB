#!/bin/bash
clear
threads_start=
threads_diff=
threads_end=
operations=
decision=

echo "// Multithreading Evironment System Analyser //s"
echo "-"
echo "Good morning and welcome to the Black MESA Transit System."
echo "This automated train is provided for the security and convenience of the Black Mesa Research Facility personnel."
echo ""
echo "1. about ..."
echo "2. Initial Start"
echo "3. Run Test"
echo "4. Plot Graph"
echo "(Press Number)"
read desicion



if decision[$desicion = "1"]
	then
#goto
else

echo "Insert the minimum amount of threads:"
read threads_start
echo ""
echo "Insert maximum amount of threads:"
read threads_end
echo ""
echo "Insert the difference (in Threads) between every single measurement:"
read threads_diff
echo ""
echo "Nr of operations executed per run:"
read operations
clear
echo "//MESA// Nr. of Threads: $threads_start - $threads_end; Steps: $threads_diff"
