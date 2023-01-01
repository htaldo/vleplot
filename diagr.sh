#!/bin/sh
#syntax: ./diagr.sh [OPTION (T OR P)] [VALUE] [SPECIES1] [SPECIES2]

option=$1
constant=$2
spec1="$(awk -f find.awk "query=$3" ./res/def.tsv)"
spec2="$(awk -f find.awk "query=$4" ./res/def.tsv)"

echo using $spec1 and $spec2

echo $option $constant $spec1 $spec2 | ./a.out 
#> output.tsv
