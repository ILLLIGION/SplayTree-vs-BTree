cmake_minimum_required(VERSION 2.8.7)
project(SplayTree_vs_BTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}<SplayTree_vs_BTree.h>)

add_library(SplayTree_vs_BTree STATIC ${CMAKE_CURRENT_SOURCE_DIR}/source/SplayTree.cpp ${CMAKE_CURRENT_SOURCE_DIR}/source/BTree.cpp)

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR} main/main.cpp)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include DESTINATION include)
