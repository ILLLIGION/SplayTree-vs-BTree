#include "catch.hpp"
#include <SplayTree.cpp>

SCENARIO("min() must return the smallest element")
{
    GIVEN("not empty tree")
    {
        SplayTree<int> tree;
        tree.insert(2, 5);
        tree.insert(6, 2);
        tree.insert(1, 34);
        tree.insert(3, 1);
        tree.insert(35, 4);
        WHEN("min()")
        {
            THEN("min is [1 34]")
            {
                REQUIRE(*tree.min()==34);
            }
        }
    }
}