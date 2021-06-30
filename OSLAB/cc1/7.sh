#!bin/bash
#Sum of first N numbers of fibonacci using while structure

echo "Enter the number of series: "
read N

#Here a and b are representing first two terms
a=-1
b=1
c=$(($a+$b))
sum=0
i=1

echo "Fibonacci series :"
while [ $i -le $N ]
do
        sum=$((sum+c))
        echo "$c"
        a=$((b))
        b=$((c))
        c=$((a+b))
        i=$((i+1))
done
#end of while structure
echo "Hence,the sum of first $N number of fibonacci series are = $sum"