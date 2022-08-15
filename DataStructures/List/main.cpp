#include <iostream>
#include "List.h"


int main() {
    std::cout << "List!" << std::endl;
    my::List<int> list1;
    my::List<int> list2 = {0, 1, 2, 3, 4};

    for (int i = 0; i < 3; ++i) {
        list1.pushBack(i);
    }
    list2 = list1;
    return 0;
}
