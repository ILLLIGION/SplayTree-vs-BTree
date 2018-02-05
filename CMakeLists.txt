cmake_minimum_required(VERSION 2.8.7)
project(SplayTree_vs_BTree)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_FILES include/SplayTree.hpp source/SplayTree.cpp include/BTree.hpp source/BTree.cpp)
set(TEST_FILES_CATCH tests/catch.hpp tests/main.cpp)
set(TEST_FILES_SPLAYTREE)
set(TEST_FILES_BTREE)
add_executable(SplayTree_vs_BTree ${SOURCE_FILES} source/main.cpp)
add_executable(Tests ${SOURCE_FILES} ${TEST_FILES_CATCH} ${TEST_FILES_BINARY} ${TEST_FILES_BINOMIAL})