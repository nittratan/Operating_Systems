echo "Finding the sum of first N natural numbers. Enter value for N"
read a

sum=0
N=0

while [ $N -lt $a ]
do
   N=`expr $N + 1`
   sum=`expr $sum + $N`
   echo $sum
done