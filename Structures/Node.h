//
// Created by luis on 24/08/17.
//

#ifndef REMOTE_MEMORY_NODE_H
#define REMOTE_MEMORY_NODE_H

template <class T>

class Node {

private:
    Node<T>* next;
    T data;

public:
    Node();
    Node(T data1);
    Node<T>* getNext();
    void setNext(Node<T>* newNode);
    bool compare(T compare);
    bool hasnext();
    T getData();
    bool hasData();
};


#endif //REMOTE_MEMORY_NODE_H