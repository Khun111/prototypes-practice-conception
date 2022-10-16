#! /usr/bin/bash
# ECHO COMMAND
# echo Hello World!
# name="Khun"
# echo "My name is $name"
# read -p "Enter your name " NAME
# echo "Hello $NAME, nice to meet you"
#   then
#   echo "Your name is Brad"
#    elif [ "$name" == "Khun" ]
#    then
#    echo "Your name is Khun"
#    else
#    echo "Your name is NOT Brad"
#    fi
#    NUM1=5
#    NUM2=31
#    if [ "$NUM1" -gt "$NUM2" ]
#    then
#        echo "$NUM1 is greater than $NUM2"
#    else
#        echo "$NUM1 is less than $NUM2"
#    fi
#    FILE="test.txt"
#    if [ -e $FILE ]
#    then
#        echo "$FILE exists"
#    else
#        echo "$FILE does not exist"
#    fi
#    read -p "Are you over 21? y/n " ANSWER
#    case $ANSWER in
#        [yY] | [yY][eE][sS])
#        echo "You can have a beer"
#       ;;
#       [nN] | [nN][oO])
#        echo "No drinking"
#        ;;
#    *)
#       echo "Please enter yes or no"
#       ;;
#    esac
#    NAMES="Khun Oluwatobi Samuel"
#    for NAME in $NAMES
#    do
#        echo "$NAME"
#    done
#    FILES=$(ls *.txt)
#    NEW="new"
#    for FILE in $FILES
#    do
#        echo "Renaming $FILE to new-$FILE"
#        mv $FILE $NEW-$FILE
#    done
#    COUNT=1
#    while read -r CURRENT_Line
#    do
#        echo "$COUNT: $CURRENT_Line"
#        ((COUNT++))
#    done < "./new-1.txt"
#    function sayHello() {
#        echo "Hello World"
#    }
#    sayHello
#    function sayHello() {
#        echo "Hello, I am $1 and I'm $2"
#    }
#    sayHello "Khun" "24"
mkdir Hello
touch "Hello/world.txt"
echo "Hello World" >> "Hello/world.txt"
echo "Created Hello/world.txt"