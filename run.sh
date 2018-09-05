Echo "Clean Dist folder"
rm -rf ./src/dist
mkdir ./src/dist

Echo "Generating polar binary"
g++ -c ./src/implementations/complex.polar.cpp
rm -rf ./src/dist/complex.polar.o
mv ./complex.polar.o ./src/dist/

Echo "Generating euclidean binary"
g++ -c ./src/implementations/complex.euclidean.cpp
rm -rf ./src/dist/complex.euclidean.o
mv ./complex.euclidean.o ./src/dist/