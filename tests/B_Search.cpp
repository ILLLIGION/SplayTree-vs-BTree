#include "catch.hpp"
#include <BTree.hpp>

SCENARIO("search() must return a value via key")
{
    GIVEN("filled tree")
    {
        Tree tree;
        tree.insert(2, 5);
        tree.insert(6, 2);
        tree.insert(1, 34);
        tree.insert(3, 1);
        tree.insert(35, 4);
        WHEN("searching a non-existing key")
        {
            THEN("search must return nullptr")
            {
                REQUIRE(tree.search(123) == nullptr);
            }
        }
        WHEN("searching an existing key")
        {
            THEN("it must return value")
            {
                REQUIRE(*tree.search(3) == 1);
            }
        }
    }
}
