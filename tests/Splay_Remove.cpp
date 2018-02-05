#include "catch.hpp"
#include <SplayTree.cpp>

SCENARIO("remove() must delete a key")
{
    GIVEN("not empty tree")
    {
        SplayTree<int> tree;
        tree.insert(2, 5);
        tree.insert(6, 2);
        tree.insert(1, 34);
        tree.insert(3, 1);
        tree.insert(35, 4);
        WHEN("removing an existing key")
        {
            tree.remove(1);
            THEN("it is removed and ")
            {
                REQUIRE(tree.root_->key == 35);
                REQUIRE(tree.root_->value == 4);
                REQUIRE(!tree.search(1));
            }
        }
        WHEN("removing an unexisting key")
        {
            tree.remove(123);
            THEN("nothing happens and root is still the same")
            {
                REQUIRE(tree.root_->key == 35);
                REQUIRE(tree.root_->value == 4);
            }
        }
    }
}
