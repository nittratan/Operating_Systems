echo "Enter two numbers"
read a b 
echo "Enter + to add, - to substract, * to mulltiply, / to divide"
read op

case "$op" in
    "+") sum=$((a+b))
        echo $sum
         ;;
    "-") sum=$((a-b))
        echo $sum
         ;;
    "*") sum=$((a*b))
        echo $sum
         ;;
    "/") sum=$((a/b))
        echo $sum
         ;;
esac