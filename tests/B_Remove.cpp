#include "catch.hpp"
#include <BTree.hpp>

SCENARIO("remove() must remove an element and restruct the tree if its needed")
{
    GIVEN("filled tree")
    {
        Tree tree;
        tree.insert(2, 5);
        tree.insert(6, 2);
        tree.insert(1, 34);
        tree.insert(3, 1);
        tree.insert(35, 4);
        tree.insert(7, 73);
        tree.insert(4, 3);
        tree.insert(12, 6);
        tree.insert(21, 43);
        tree.insert(13, 12);
        WHEN("remove")
        {
            tree.remove(7);
            THEN("tree must restruct")
            {
                REQUIRE(tree.root->keys[0].key == 2);
                REQUIRE(tree.root->keys[1].key == 6);
                REQUIRE(tree.root->keys[2].key == 13);
                REQUIRE(tree.root->count == 3);
                REQUIRE(tree.root->countSons == 2);

                REQUIRE(tree.root->children[0]->keys[0].key==1);
                REQUIRE(tree.root->children[0]->count==1);
                REQUIRE(tree.root->children[0]->countSons==0);

                REQUIRE(tree.root->children[1]->keys[0].key==3);
                REQUIRE(tree.root->children[1]->keys[1].key==4);
                REQUIRE(tree.root->children[1]->count==2);
                REQUIRE(tree.root->children[1]->countSons==0);

                REQUIRE(tree.root->children[2]->keys[0].key==12);
                REQUIRE(tree.root->children[2]->count==1);
                REQUIRE(tree.root->children[2]->countSons==0);

                REQUIRE(tree.root->children[3]->keys[0].key==21);
                REQUIRE(tree.root->children[3]->keys[1].key==35);
                REQUIRE(tree.root->children[3]->count==2);
                REQUIRE(tree.root->children[3]->countSons==0);
            }
        }
    }
}
