
echo "Producing the sum of first N numbers in Fibbonacci Series, Enter N"
read N
a=0
  

b=1 
sum=0
echo "The Fibonacci series is : "
   
for (( i=0; i<N; i++ ))
do
    echo -n "$sum "
    fn=$((a + b))
    a=$b
    b=$fn
    sum=$((sum+a))
done