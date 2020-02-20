printf "running assignment 2...\n"
g++ type-sizes.cpp -o sizes
./sizes > type-sizes.info

printf "\n-----------------------------\n      displaying results       \n----------------------------- \n \n"

cat type-sizes.info

printf "\n \n"
