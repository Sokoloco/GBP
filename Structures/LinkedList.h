//
// Created by luis on 24/08/17.
//

#ifndef REMOTE_MEMORY_LINKEDLIST_H
#define REMOTE_MEMORY_LINKEDLIST_H
#include "Node.cpp"

template <class T>
class LinkedList{
private:
    Node<T>* first;
    Node<T>* last;
    int size;
public:
    LinkedList<T>();
    void add(T data);

    void remove(T data);

    T* search(T value);

    bool empty();

    void run();

    T* get(int n);

    int getSize();

    void swap(Node<T> *b4, Node<T> *x, Node<T> *y);

    void sort();
};


#endif //REMOTE_MEMORY_LINKEDLIST_H