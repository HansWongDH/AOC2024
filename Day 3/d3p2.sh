input_file="day3.txt"
input=$(cat "$input_file")

valid_patterns=$(echo "$input" | grep -oP "(?:don't\(\)|do\(\)|mul\(\d+,\d+\))" | tr '\n' ' ')

sum=0

cleaned_input=$(echo "$valid_patterns" | sed -E 's/don'\''t\(\)[^d]*(do\(\))?/ \1/g')

# echo "$matches"

for match in $cleaned_input; do 
    x=$(echo "$match" | grep -oP 'mul\(\K\d+') 
    y=$(echo "$match" | grep -oP '(?<=,)\d+(?=\))') 
    sum=$((sum + x * y)) 
done

echo "$sum"
