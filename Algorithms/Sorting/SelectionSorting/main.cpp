#include <iostream>
#include <vector>

// O(N^2)
template<typename Collection, typename Comparator = std::less<>>
void selectionSorting(Collection& collection, Comparator comparator = Comparator{}) noexcept {
    for (typename Collection::size_type i = 0; i < collection.size() - 1; ++i) {
        typename Collection::size_type keyElementIndex = i;
        for (typename Collection::size_type j = i + 1; j < collection.size(); ++j) {
            if (comparator(collection[j], collection[keyElementIndex])) {
                keyElementIndex = j;
            }
        }

        if (keyElementIndex != i) {
            std::swap(collection[i], collection[keyElementIndex]);
        }
    }
}

int main() {
    std::vector<int> vector = { 4, 7, 1, 5, 2, 9, 4, 7, 2, 9, 4 };

    std::cout << "Not sorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    selectionSorting(vector, [](int a, int b) { return a > b; });

    std::cout << "\nSorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    return 0;
}