#!/bin/bash
ARG="4 3 2 1 0"
echo
echo "--CHECKER RESULTS FOR ARG--"
./push_swap $ARG | ./checker_Mac $ARG
echo "------NUMBER OF MOVES------"
./push_swap $ARG | wc -l
echo
echo "---------VALGRIND----------"
valgrind ./push_swap $ARG
