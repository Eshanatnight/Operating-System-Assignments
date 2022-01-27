read -p "Enter number of Elements: " numOfElem
i=0
sum=0
while(($i < $numOfElem))
do
    read -p "Enter Number: " num
    sum=$(( $sum + $num ))
    i=$(( $i + 1 ))
done
avg=$(( $sum / $numOfElem ))

echo "Average is: $avg"

