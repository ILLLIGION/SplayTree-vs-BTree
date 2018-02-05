#ifndef BTREE_BTREE_H
#define BTREE_BTREE_H

#include <iostream>
#include <vector>
#include <memory>

#define t 2
//const int t=2;

struct element
{
    int key;
    int value;
    bool flag;
    element();
    element(int key_, int value_);
    void print_element();
    element& operator=(const element& right);
};

struct BNode {
    element keys[2*t];
    BNode *children[2*t+1];
    BNode *parent;
    int count; //количество ключей
    int countSons; //количество сыновей
    bool leaf;
    bool equal (BNode *node2);
};

class Tree {
public:
    BNode *root;
private:
    void insert_to_node(int key_, int value_, BNode *node);
    void sort(BNode *node);
    void restruct(BNode *node);
    void deletenode(BNode *node);
    element* searchKey(int key, BNode *node);
    void remove(int key, BNode *node);
    void removeFromNode(int key, BNode *node);
    void removeLeaf(int key, BNode *node);
    void lconnect(BNode *node, BNode *othernode);
    void rconnect(BNode *node, BNode *othernode);
    void repair(BNode *node);


    //void Split_Child (BNode *node, int i);
    //void Insert_Nonfull(BNode *node, int key_, int value_);

public:
    Tree();
    ~Tree();


    void insert(int key_, int value_);
    int search(int key);
    void remove(int key);
    int max(BNode *node);
    int min(BNode *node);


    auto print(std::ostream& out, BNode* node, int level) const noexcept -> bool;
    auto operator == (const Tree& tree) -> bool;
};

#endif //BTREE_BTREE_H
