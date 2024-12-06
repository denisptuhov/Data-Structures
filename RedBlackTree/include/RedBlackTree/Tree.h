#pragma once
#include <utility>

#include <RedBlackTree/Node.h>

namespace rbt {
    template <typename T>
    class Tree {
    private:
        static const node_ptr_t<T> nil = &Node<T>::nil;
    
    public:
        using value_t = T;

        Tree();

        node_ptr_t<T> find(const T &value);

        std::pair<bool, node_ptr_t<T>> insert(const T &value);

    private:
        std::pair<bool, node_ptr_t<T>> insertInTree(const T &value);

        node_ptr_t<T> rotateLeft(node_ptr_t<T> around);
        void rotateRight(node_ptr_t<T> around);

        node_ptr_t<T> root;
    };

    template <typename T>
    Tree<T>::Tree() : root(nil) { }

    template <typename T>
    node_ptr_t<T> Tree<T>::find(const T &value) {
        auto elem = root;

        while (elem != nil) {
            if (value == elem->value) {
                break;
            }
            
            if (value < elem->value) {
                elem = elem->left;
            } else {
                elem = elem->right;
            }
        }

        return (elem == nil) ? nullptr : elem;
    }

    template <typename T>
    std::pair<bool, node_ptr_t<T>> Tree<T>::insert(const T &value) {
        auto [result, elem] = insertInTree(value);
        if (!result) {
            return elem;
        }

        auto parent = elem->parent;
        while (elem != root && parent->color == Color::RED) {
            auto grandpa = parent->parent;
            
            node_ptr_t<T> other{nullptr};
            if (parent->side == Side::LEFT) {
                other = grandpa->right;
            } else {
                other = grandpa->left;
            }

            if (other->color == Color::RED) {
                other->color = Color::BLACK;
                parent->color = Color::BLACK;
                grandpa->color = Color::RED;

                elem = grandpa;
                continue;
            }

            if (elem->side == Side::RIGHT) {
                elem = parent;
                parent = rotateLeft(parent);
            }
        }

        if (elem == root && elem->color == Color::RED) {
            elem->color = Color::BLACK;
        }

        return {true, elem};
        
    }


    template <typename T>
    std::pair<bool, node_ptr_t<T>> Tree<T>::insertInTree(const T &value) {
        if (root == nil) {
            root = new Node(value);
            return root;
        }
        
        auto elem = root;
        while (true) {
            if (value == elem->value) {
                return {false, elem};
            }

            if (value < elem->value) {
                if (elem->left == &nil) {
                    elem->left = new Node(value, Side::LEFT, elem);
                    return {true, elem->left};
                }
                elem = elem->left;
            } else {
                if (elem->right == &nil) {
                    elem->right = new Node(value, Side::RIGHT, elem);
                    return {true, elem->right};
                }
                elem = elem->right;
            }
        }
    }

    template <typename T>
    node_ptr_t<T> Tree<T>::rotateLeft(node_ptr_t<T> around) {
        auto leftSubTree = around->right->left;
        around->right->left = around;
        around->right = leftSubTree;

        return around->right;
    }

    template <typename T>
    void Tree<T>::rotateRight(node_ptr_t<T> around) {
        auto rightSubTree = around->left->right;
        around->left->right = around;
        around->left = rightSubTree;

        return around->left;
    }
}