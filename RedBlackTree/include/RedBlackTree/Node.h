#pragma once
#include <RedBlackTree/Types.h>

namespace rbt {
    template <typename T>
    struct Node;
    
    template <typename T>
    using node_ptr_t = Node<T>*;
    
    template <typename T>
    struct Node {
        static const Node<T> nil;

        Node() = default;
        Node(const T &value, Side side = Side::NONE, node_ptr_t<T> parent = nullptr);

        T value{};
        Color color{Color::BLACK};

        node_ptr_t<T> left{&nil};
        node_ptr_t<T> right{&nil};

        Side side{Side::NONE};
        node_ptr_t<T> parent{nullptr};
    };

    template <typename T>
    const Node<T> Node<T>::nil;

    template <typename T>
    Node<T>::Node(const T &value, Side side, node_ptr_t<T> parent) : value(value), color(Color::RED), side(side), parent(parent) {}
}