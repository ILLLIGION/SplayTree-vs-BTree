#include "catch.hpp"
#include <SplayTree.cpp>

SCENARIO("splay() must put a node to the root")
{
    GIVEN("not empty tree")
    {
        SplayTree<int> tree;
        tree.insert(2, 5);
        tree.insert(6, 2);
        tree.insert(1, 34);
        tree.insert(3, 1);
        tree.insert(35, 4);
        WHEN("splaying a key")
        {
            tree.splay(tree.root_->left_->left_->left_);
            THEN("it becomes root")
            {
                REQUIRE(tree.root_->key == 1);
                REQUIRE(tree.root_->value == 34);
            }
        }
    }
}