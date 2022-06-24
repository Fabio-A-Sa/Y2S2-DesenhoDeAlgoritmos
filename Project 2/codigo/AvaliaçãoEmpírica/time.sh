TIMEFORMAT='%3R'
time {
    cd ..
    cd build/
    ./proj2 $1 $2 graph$3.txt 1 200 < $4
    cd ..
    cd AvaliaçãoEmpírica/
} >> output.csv