#include "catch.hpp"
#include <BTree.hpp>

SCENARIO("insert() must add a key to the b_tree")
{
    GIVEN("Empty tree")
    {
        Tree empty_tree;
        WHEN("Adding a key")
        {
            empty_tree.insert(2,5);
            THEN("Node must be in the root")
            {
                REQUIRE(empty_tree.root->keys[0].key == 2);
                REQUIRE(empty_tree.root->keys[0].value == 5);
            }
        }
    }
    GIVEN("not empty tree")
    {
        Tree tree;
        WHEN("Adding keys")
        {
            tree.insert(2, 5);
            tree.insert(6, 2);
            tree.insert(1, 34);
            tree.insert(3, 1);
            tree.insert(35, 4);
            THEN("root must be the last element added")
            {
                REQUIRE(tree.root->keys[0].key == 2);
                REQUIRE(tree.root->keys[0].value == 5);
                REQUIRE(tree.root->count == 1);
                REQUIRE(tree.root->countSons == 2);
                REQUIRE(tree.root->children[0]->keys[0].key==1);
                REQUIRE(tree.root->children[0]->keys[0].value==34);
                REQUIRE(tree.root->children[0]->count==1);
                REQUIRE(tree.root->children[0]->countSons==0);
                REQUIRE(tree.root->children[1]->keys[0].key==3);
                REQUIRE(tree.root->children[1]->keys[0].value==1);
                REQUIRE(tree.root->children[1]->keys[1].key==6);
                REQUIRE(tree.root->children[1]->keys[1].value==2);
                REQUIRE(tree.root->children[1]->keys[2].key==35);
                REQUIRE(tree.root->children[1]->keys[2].value==4);
                REQUIRE(tree.root->children[1]->count==3);
                REQUIRE(tree.root->children[0]->countSons==0);
            }
        }
    }
}
