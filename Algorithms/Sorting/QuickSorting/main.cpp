#include <iostream>
#include <vector>

template<typename Collection>
using SizeType = typename Collection::size_type;

//template<typename Collection, typename Comparator = std::less<>, typename iterator = typename Collection::iterator>
//void QuickSorting(Collection& collection, const iterator& begin, const iterator& end,
//                  Comparator comparator = Comparator{}) noexcept {
//    QuickSorting(collection, /*somehow get start and end indexes from iterators*/ 0, collection.size() - 1, comparator);
//}

template<typename Collection, typename Comparator = std::less<>>
void QuickSorting(Collection& collection, const SizeType<Collection>& left,
                  const SizeType<Collection>& right, Comparator comparator = Comparator{}) noexcept {

    SizeType<Collection> l = left;
    SizeType<Collection> r = right;
    typename Collection::value_type key = collection[(left + right) / 2];

    while (l <= r) {
        while (comparator(collection[l], key)) {
            l++;
        }

        while (comparator(key, collection[r])) {
            r--;
        }

        if (l <= r) {
            std::swap(collection[l++], collection[r--]);
        }
    }

    if (l < right) {
        QuickSorting(collection, l, right, comparator);
    }

    if (r > left) {
        QuickSorting(collection, left, r, comparator);
    }
}

int main() {
    std::vector<int> vector = { 4, 7, 1, 5, 2, 9, 4, 7, 2, 9, 4 };

    std::cout << "Not sorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    QuickSorting(vector, 0, vector.size() - 1, [](int a, int b) { return a > b; });
//    QuickSorting(vector, 0, vector.size() - 1,
//                 [](int a, int b) { return std::abs(a - 5) < std::abs(b - 5); });

    std::cout << "\nSorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";


//    std::string str("ejvnjewrjvlnir");
//    QuickSorting(str, 0, str.size() - 1, [](char a, char b) { return a > b; });
//    std::cout << "Sorted string: " << str;

    return 0;
}