#ifndef SPLAYTREE_SPLAYTREE_H
#define SPLAYTREE_SPLAYTREE_H

#include <iostream>
#include <memory>

template <typename T>
class SplayTree
{
public:
    struct Node {
        std::shared_ptr<Node> left_;
        std::shared_ptr<Node> right_;
        std::shared_ptr<Node> parent_;
        short key;
        T value;

        Node(short key_, T value_);
        ~Node();

        auto equal(std::shared_ptr<Node> tree) const noexcept -> bool;
    };

    SplayTree();
    // SplayTree(const std::initializer_list<T>& list);
    ///Insert///
    auto insert(const short key, const T& value) -> bool;
    ///Search///
    auto search(const short key) -> const T*;
    ///Remove///
    auto remove(const short key) -> bool;
    auto merge(std::shared_ptr<Node> left_tree, std::shared_ptr<Node> right_tree) -> bool;
    auto max_merge (std::shared_ptr<Node> left_tree) const -> std::shared_ptr<Node>;
    ///Min///
    auto min() const -> const T*;
    ///Max///
    auto max() const -> const T*;
    ///Splay///
    auto rotate_left(std::shared_ptr<Node> node) -> void;
    auto rotate_right(std::shared_ptr<Node> node) -> void;
    auto splay(std::shared_ptr<Node> node) -> void;
    ///Print///
    auto print(std::ostream& out, std::shared_ptr<Node> node, int level) const noexcept -> bool;

    auto operator == (const SplayTree& tree) -> bool;

    std::shared_ptr<Node> root_;
};
#endif //SPLAYTREE_SPLAYTREE_H