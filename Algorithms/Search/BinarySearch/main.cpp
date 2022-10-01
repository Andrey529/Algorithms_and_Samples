#include <iostream>
#include <vector>

template<typename Collection>
using ValType = typename Collection::value_type;

template<typename Collection>
using SizeType = typename Collection::size_type;

// O(logN)
template<typename Collection>
int binarySearch(const Collection& collection, const ValType<Collection>& value) {
    SizeType<Collection> begin = 0u;
    SizeType<Collection> end = collection.size() - 1;
    SizeType<Collection> mid = end / 2;

    while (begin <= end) {
        ValType<Collection> guess = collection[mid];
        if (guess < value) {
            begin = mid + 1;
            mid = (begin + end) / 2;
        }
        else if (guess > value) {
            end = mid - 1;
            mid = (begin + end) / 2;
        }
        else {
            return static_cast<int>(mid);
        }
    }
    return -1;
}

int main(){
    std::vector<int> arr = {1, 2, 3, 4, 6, 7, 8};

    std::cout << binarySearch(arr, 6) << std::endl;
    std::cout << binarySearch(arr, 5) << std::endl;

    return 0;
}