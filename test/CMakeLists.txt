# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link Cache Cachetest GTest and pthread library
include_directories(${avltree_SOURCE_DIR}/include)

# Add source files to executable
add_executable(test main_test.cpp )
target_sources(test PUBLIC ${avltree_SOURCE_DIR}/src/avltree.cpp)

target_link_libraries(test ${GTEST_LIBRARIES} pthread)
