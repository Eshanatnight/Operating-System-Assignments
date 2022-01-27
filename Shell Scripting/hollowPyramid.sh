#Problem : Print an Inverted Hollow Pyramid
echo "No. of rows in the Hollow Pyramid : "
read rows
#store number of rows
for (( x = 1 ; x <= $rows ; ++x))
do
    for (( y = x ; y <= $rows ; ++y))
    do
        if (( x == 1 || y == x || y == $rows ))
        then
            echo -n "*"      #print * at the borders of the triangle
        else
            echo -n " "      #print spaces at the rest of the places
        fi
    done

    echo ""                 #change the line
done