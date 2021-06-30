echo "Enter three nummbers as input  "
read a b c 
if [ $a -gt $b ] && [ $a -gt $c ]
then
    echo "$a is the greatest"
    if [ $b -gt $c ]
    then 
        echo "$c is smallest"
    else
        echo "$b is smallest"
    fi
elif [ $b -gt $a ] && [ $b -gt $c ]
then
    echo "$b is greatest"
    if [ $a -gt $c ]
    then 
        echo "$c is smallest"
    else
        echo "$a is smallest"
    fi
else
    echo "$c is greatest"
    if [ $a -gt $b ]
    then 
        echo "$b is smallest"
    else
        echo "$a is smallest"
    fi
fi

