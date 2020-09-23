cmake_minimum_required (VERSION 3.1)

project (avltree)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)

add_subdirectory(debug)

add_subdirectory(test)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
