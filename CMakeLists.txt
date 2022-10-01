cmake_minimum_required(VERSION 3.21)
project(AlgorithmsAndDataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(AlgorithmsAndDataStructures main.cpp)
add_subdirectory(DataStructures/List)
add_subdirectory(DataStructures/Stack)
add_subdirectory(DataStructures/ComplexNumber)
add_subdirectory(Algorithms/Search/BinarySearch)
add_subdirectory(Algorithms/Sorting/SelectionSorting)
