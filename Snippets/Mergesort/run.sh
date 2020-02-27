g++ merge-sort.cpp -o MergeSort
while true
do
    clear
    echo "Running again"
    ./MergeSort | tr , '\n' | block 1 10
    sleep 1s
done