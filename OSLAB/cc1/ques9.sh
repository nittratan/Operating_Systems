
echo "Enter two strings"
read s1
read s2

if [ -z $s1 ] || [ -z $s2 ];
then
    echo "Null string"
else
    if [ $s1 == $s2 ]
    then 
        echo "Equal"
    else
        echo "Not Equal"
    fi

    if [[ $s1 =~ ['!@#$%^&*()_+'] ]] || [[ $s2 =~ ['!@#$%^&*()_+'] ]]
    then
        echo "One of them contains a special character"
    else
        echo "None of them contain a special character"
    fi
fi
