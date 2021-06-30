
echo "Reading a number, Printing its multiplication table"
read n

op=1
for (( i=1; i<=10; i++ ))
do
    op=$((n*i))
    echo "$op "
    
done