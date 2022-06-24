# Setup project

mkdir build
cd build
cmake ..
cmake --build .
clear

# Running helper

./proj2 --help 

# Testing each case with graph 10 and different inputs

echo ""
echo "Case 1.1"
./proj2 1 1 graph10.txt 1 10

echo ""
echo "Case 1.2"
./proj2 1 2 graph10.txt 3 10

echo ""
echo "Case 2.1"
./proj2 2 1 graph10.txt 1 10 6

echo ""
echo "Case 2.2"
echo "Original capacity and paths:"
cat "../input/2.2"
echo ""
echo "New capacity: 8"
./proj2 2 2 graph10.txt 3 10 8      # Need to write "2.2" in terminal

echo ""
echo "Case 2.3"
./proj2 2 3 graph10.txt 1 9

echo ""
echo "Case 2.4"
echo "Original capacity and paths:"
cat "../input/2.4"
echo ""
./proj2 2 4 graph10.txt 1 10        # Need to write "2.4" in terminal

echo ""
echo "Case 2.5"
echo "Original capacity and paths:"
cat "../input/2.5"
echo ""
./proj2 2 5 graph10.txt 1 10        # Need to write "2.5" in terminal