#include "catch.hpp"
#include <BTree.hpp>

SCENARIO("Max() must return the biggest element")
{
    GIVEN("not empty tree")
    {
        Tree tree;
        tree.insert(2, 5);
        tree.insert(6, 2);
        tree.insert(1, 34);
        tree.insert(3, 1);
        tree.insert(35, 4);
        WHEN("max()")
        {
            THEN("max is [35 4]")
            {
                REQUIRE(tree.max(tree.root) == 4);
            }
        }
    }
}
