#include <iostream>
#include <vector>

template<typename Collection>
using ValType = typename Collection::value_type;

template<typename Collection>
using SizeType = typename Collection::size_type;

// O(N)
template<typename Collection>
int linearSearch(const Collection& collection, const ValType<Collection>& value) noexcept {
    for (SizeType<Collection> i = 0; i < collection.size(); ++i) {
        if (collection[i] == value) {
            return i;
        }
    }

    return -1;
}

int main(){
    std::vector<int> arr = {1, 2, 3, 4, 6, 7, 8};

    std::cout << linearSearch(arr, 6) << std::endl;
    std::cout << linearSearch(arr, 5) << std::endl;

    return 0;
}