
echo "Reading a Number, Writing it in reverses order and producing Sum of individual Digits"
read num
rem=0
sm=0
revdig=0
while [ $num -gt 0 ]
do
    rem=`expr $num % 10`
    echo $rem 
    sm=$((sm+rem))
    num=$((num/10))
    revdig=$((revdig*10+rem))
    
done 
echo "Reversed: $revdig, Sum of Digits: $sm"