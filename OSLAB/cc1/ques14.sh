# !/bin/bash

for item in *
do
    if [ -f $item ]
    then
        echo "----------------$item----------------"
        if [ -x $item ]
        then
            echo "File in Executable mode"
            chmod -x $item
            echo "Executable permission Removed!"
        fi
        if [ -w $item ]
        then
            echo "File in Write mode"
            chmod -w $item
            echo "Write permission Removed!"
        fi
    if [ -r $item ]
    then
        echo "Already in read mode(r--r--r--)"
    else
        chmod +r $item
        echo "Now the read permission granted "
    fi
        echo "final permission"
        ls -al $item
    fi
    echo
done