//
// Created by luis on 24/08/17.
//

#include <iostream>
#include "Node.h"

template <class T>
Node<T>::Node() {
    next = NULL;
    data = NULL;
}

template <class T>
Node<T>::Node(T data1){
    next = NULL;
    data = data1;
}

template <class T>
void Node<T>::setNext(Node<T>* newNode) {
    next = newNode;
}
template <class T>
Node<T>* Node<T>::getNext() {
    return next;
}



template <class T>
bool Node<T>::hasnext() {
    return next != NULL;
}

template <class T>
T Node<T>::getData(){
    return data;
}

template <class T>
bool Node<T>::hasData(){
    return data == NULL;
}

template class Node<int>;