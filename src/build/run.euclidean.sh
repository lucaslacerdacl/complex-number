g++ -c ../implementations/complex.euclidean.cpp
g++ -c ../main.cpp

g++ complex.euclidean.o main.o -o main.exe

./main.exe