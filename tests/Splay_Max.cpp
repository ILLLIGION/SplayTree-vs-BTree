#include "catch.hpp"
#include <SplayTree.cpp>

SCENARIO("max() must return the biggest element")
{
    GIVEN("not empty tree")
    {
        SplayTree<int> tree;
        tree.insert(2, 5);
        tree.insert(6, 2);
        tree.insert(1, 34);
        tree.insert(3, 1);
        tree.insert(35, 4);
        WHEN("max()")
        {
            THEN("min is [35 4]")
            {
                REQUIRE(*tree.max()==4);
            }
        }
    }
}