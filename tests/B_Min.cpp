#include "catch.hpp"
#include <BTree.hpp>

SCENARIO("Min() must return the smallest element")
{
    GIVEN("not empty tree")
    {
        Tree tree;
        tree.insert(2, 5);
        tree.insert(6, 2);
        tree.insert(1, 34);
        tree.insert(3, 1);
        tree.insert(35, 4);
        WHEN("min()")
        {
            THEN("min is [1 34]")
            {
                REQUIRE(tree.min(tree.root) == 34);
            }
        }
    }
}