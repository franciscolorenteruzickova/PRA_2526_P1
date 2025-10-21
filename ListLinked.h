#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    // Constructor
    ListLinked() : first(nullptr), n(0) {}

    // Destructor
    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;
            delete fisrt;
            aux = first;
        }
    }

    // Tamaño
    int size() const  override {
        return n;
    }

    // Está vacía
    bool empty() const override {
        return n == 0;
    }

    // Insertar en posición
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición fuera de rango");

        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;

            prev->next = new Node<T>(e, prev->next);
        }

        n++;
    }

    // Añadir al final
    void append(T e) override {
        insert(n, e); // insert al final
    }

    // Añadir al principio
    void prepend(T e) override {
        insert(0, e); // insert al inicio
    }

    // Eliminar en posición
    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango");

        T value;
        if (pos == 0) {
            Node<T>* temp = first;
            value = temp->data;
            first = first->next;
            delete temp;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;

            Node<T>* toDelete = prev->next;
            value = toDelete->data;
            prev->next = toDelete->next;
            delete toDelete;
        }

        n--;
        return value;
    }

    // Obtener elemento
    T get(int pos) const override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango");

        Node<T>* current = first;
        for (int i = 0; i < pos; i++)
            current = current->next;

        return current->data;
    }

    // Buscar elemento
    int search(T e) const override {
        Node<T>* current = first;
        int index = 0;
        while (current != nullptr) {
            if (current->data == e)
                return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    // Acceso con operador []
    T operator[](int pos) {
        return get(pos); // usa get para reaprovechar código
    }

    // Imprimir lista
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data;
            if (current->next != nullptr)
                out << " -> ";
            current = current->next;
        }
        out << " -> nullptr";
        return out;
    }
};

#endif

