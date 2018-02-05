cmake_minimum_required(VERSION 2.8.7)
project(SplayTree_vs_BTree)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/source)

set(SOURCE_FILES include/SplayTree.hpp source/SplayTree.cpp include/BTree.hpp source/BTree.cpp)
set(TEST_FILES_CATCH tests/catch.hpp tests/main.cpp)
set(TEST_FILES_SPLAYTREE tests/Splay_Insert.cpp tests/Splay_Search.cpp tests/Splay_Remove.cpp tests/Splay_Splay.cpp
                                                                        tests/Splay_Min.cpp tests/Splay_Max.cpp)
set(TEST_FILES_BTREE tests/B_Insert.cpp tests/B_Max.cpp tests/B_Min.cpp tests/B_Search.cpp tests/B_Remove.cpp)
add_executable(SplayTree_vs_BTree ${SOURCE_FILES} source/main.cpp)
add_executable(Tests ${SOURCE_FILES} ${TEST_FILES_CATCH} ${TEST_FILES_SPLAYTREE} ${TEST_FILES_BTREE})