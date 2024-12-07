#!/bin/bash
input_file="day3.txt"

input=$(cat "$input_file")

valid_muls=$(echo "$input" | grep -oP 'mul\(\d+,\d+\)')

sum=0

for match in $valid_muls; do 
    x=$(echo "$match" | grep -oP 'mul\(\K\d+') 
    y=$(echo "$match" | grep -oP '(?<=,)\d+(?=\))') 
    sum=$((sum + x * y)) 
done


echo $sum