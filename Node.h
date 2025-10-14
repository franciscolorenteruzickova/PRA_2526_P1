#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    // Constructor: inicializa los atributos
    Node(T data, Node<T>* next = nullptr)
        : data(data), next(next) {}

    // Sobrecarga del operador << para imprimir el nodo
    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
        out << node.data;
        return out;
    }
};

#endif

