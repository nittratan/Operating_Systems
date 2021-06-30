echo "Please Enter the marks for 5 subjects, between 0 and 100"
read a 
read b
read c
read d 
read e 
sum=$((a+b+c+d+e))

echo "Total marks $sum/500 "
echo "Grade Received: "
if [ $sum -gt 200 ]
then 
    if [ $sum -gt 250 ]
    then 
        if [ $sum -gt 300 ]
        then 
            if [ $sum -gt 350 ]
            then 
                if [ $sum -gt 400 ]
                then
                    if [ $sum -gt 450 ]
                    then 
                        echo "A"
                    else
                        echo "B1"
                    fi
                else 
                    echo "B2"
                fi
            else
                echo "C"
            fi 
        else 
            echo "D"
        fi 
    else 
        echo "E"
    fi 
else
    echo "F"
fi