set -e

cd ./src/dist
rm -rf ./main.exe

imports=()

cmdLine="./complex.${1}.o ./main.o"

for import in "${imports[@]}"
    do
        arrImport=(${import//;/ })
        importFile=(${arrImport[1]})
        importDependencie=(${arrImport[0]})

        cmdLine+=" ../../packages/${importDependencie}/src/dist/${importFile}"

        
done

g++ ${cmdLine} -o main.exe

./main.exe