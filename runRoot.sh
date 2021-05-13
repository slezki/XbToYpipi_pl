#!/bin/bash

arg1=$1

root -l -b -q Run.pL_${arg1}.C
#root -l Run.pL_${arg1}.C

rm ${arg1}_C*

