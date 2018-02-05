#include "catch.hpp"
#include <SplayTree.cpp>

SCENARIO("search() must find a value via a key and splay it")
{
    GIVEN("not empty tree")
    {
        SplayTree<int> tree;
        tree.insert(2, 5);
        tree.insert(6, 2);
        tree.insert(1, 34);
        tree.insert(3, 1);
        tree.insert(35, 4);
        WHEN("searching an existing key")
        {
            tree.search(1);
            THEN("it must become root")
            {
                REQUIRE(tree.root_->key == 1);
                REQUIRE(tree.root_->value == 34);
            }
        }
        WHEN("searching an unexisting key")
        {
            tree.search(123);
            THEN("nothing happens and root is still the same")
            {
                REQUIRE(tree.root_->key == 35);
                REQUIRE(tree.root_->value == 4);
            }
        }
    }
}
