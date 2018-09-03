g++ -c ../implementations/complex.polar.cpp
g++ -c ../main.cpp

g++ complex.polar.o main.o -o main.exe

./main.exe