#include <iostream>
#include <vector>

// O(N^2)
template<typename Collection, typename Comparator = std::less<>>
void insertionSorting(Collection& collection, Comparator comparator = Comparator{}) noexcept {
    for (typename Collection::size_type i = 1; i < collection.size(); ++i) {
        typename Collection::value_type element = collection[i];

        // inserting collection[i] into sorted collection of elements
        typename Collection::value_type j = i - 1;

        while (j >= 0 && comparator(collection[j], element)) {
            collection[j + 1] = collection[j];
            j = j - 1;
        }

        collection[j + 1] = element;
    }
}

int main() {
    std::vector<int> vector = { 4, 7, 1, 5, 2, 9, 4, 7, 2, 9, 4 };

    std::cout << "Not sorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    insertionSorting(vector, [](int a, int b) { return a > b; });

    std::cout << "\nSorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    return 0;
}