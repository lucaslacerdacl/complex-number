set -e

echo "Getting packages"
{
    dependencies=()

    rm -rf ./packages
    mkdir packages

    for dependencie in "${dependencies[@]}"
        do
            arrDependencie=(${dependencie//;/ })
            dependencieURL=(${arrDependencie[1]})
            dependencieName=(${arrDependencie[0]})

            git clone "${dependencieURL}"
            mv ./"${dependencieName}" ./packages/"${dependencieName}"

            cd ./packages/"${dependencieName}"
            ./run.sh
            if [ -f "../../run.sh" ] && [ "$(ls -A ./packages)" ]
            then
                cp -r -f ./packages/* ../../packages
            fi
            cd ../../
    done
} &> /dev/null

if [ ! -d "./src/dist" ]
then
    mkdir ./src/dist
fi

echo -e "\nGenerating polar binary"
{
    g++ -c ./src/implementations/complex.polar.cpp
    rm -rf ./src/dist/complex.polar.o
    mv ./complex.polar.o ./src/dist/
} &> /dev/null

echo -e "\nGenerating euclidean binary"
{
    g++ -c ./src/implementations/complex.euclidean.cpp
    rm -rf ./src/dist/complex.euclidean.o
    mv ./complex.euclidean.o ./src/dist/
} &> /dev/null

echo -e "\nGenerating main binary"
{
    g++ -c ./src/main.cpp
    rm -rf ./src/dist/main.o
    mv ./main.o ./src/dist/
} &> /dev/null