#include "catch.hpp"
#include <SplayTree.cpp>

SCENARIO("insert() must add a key to the tree and splay it")
{
    GIVEN("Empty tree")
    {
        SplayTree<int> empty_tree;
        WHEN("Adding a key")
        {
            empty_tree.insert(2,5);
            THEN("Node must be in the root")
            {
                REQUIRE(empty_tree.root_->key == 2);
                REQUIRE(empty_tree.root_->value == 5);
            }
        }
    }
    GIVEN("not empty tree")
    {
        SplayTree<int> tree;
	    WHEN("Adding keys")
        {
            tree.insert(2, 5);
            tree.insert(6, 2);
            tree.insert(1, 34);
            tree.insert(3, 1);
            tree.insert(35, 4);
            THEN("root must be the last element added")
            {
                REQUIRE(tree.root_->key == 35);
                REQUIRE(tree.root_->value == 4);
            }
        }
    }
}
