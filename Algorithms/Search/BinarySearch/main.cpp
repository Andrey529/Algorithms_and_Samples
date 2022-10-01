#include <iostream>
#include <vector>

template<typename T>
int binarySearch(const std::vector<T>& arr, const T& item) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        T guess = arr[mid];
        if (guess == item) {
            return mid;
        }
        else if (guess > item) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    std::vector<int> arr{1, 2, 3, 4, 6, 7, 8};

    std::cout << binarySearch(arr, 6) << std::endl;
    std::cout << binarySearch(arr, 5) << std::endl;

    return 0;
}