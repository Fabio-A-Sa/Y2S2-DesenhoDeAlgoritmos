echo "Case 1":
for type in {1..2}
do
    echo "Type $type:"
    for ((i=1000; i<=10000; i+=1000))  
    do  
        python3 graphGenerator.py "$i";
        bash time.sh "1" "$type" "$i" "100"
        rm -r "../input/graph$i.txt";
    done 
done

echo "Case 2"
for type in 1 3
do
    echo "Type $type"
    for ((i=1000; i<=10000; i+=1000))  
    do  
        python3 graphGenerator.py "$i";
        bash time.sh "2" "$type" "$i" "20"
        rm -r "../input/graph$i.txt";
    done 
done

echo "Type 2"
for ((i=10; i<=100; i+=10))  
do  
    bash time.sh "2" "2" "10000" "$i" "input.txt"
done 


for type in 4 5
do
    echo "Type $type"
    for ((i=5; i<=50; i+=5))  
    do  
        bash time.sh "2" "$type" "$i" "$i"
    done 
done