#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
    first = NULL;
    last = NULL;
    size = 0;
}

template <class T>
/**
 * Adds an element to the list
 * @tparam T type of element to be added
 * @param data data that is going to be added
 */
void LinkedList<T>::add(T data) {
        Node<T>*temp = new Node<T>(data);
        if(first==NULL)
        {
            first=temp;
            last=temp;
            temp=NULL;
        }
        else
        {
            last->setNext(temp);
            last=temp;
        }
    size++;
}

/**
 * Removes a node from the list
 * @tparam T node to be removed
 * @param data data to compare
 */
template <class T>
    void LinkedList<T>::remove(T data) {
        if (!first)return;
        if (first == last && first->getData() == data){
            first = last = NULL;
            size--;}
        else if (first->getData() == data){
            Node<T>* curr = first;
            first = first->getNext();
            delete(curr);
        size--;}
        else {
            Node<T>* curr = first, *bhnd = curr;
            while (curr != NULL) {
                if (curr->getData() == data) {
                    bhnd->setNext(curr->getNext());
                    if(last == curr){
                        last = bhnd;
                    }
                    delete(curr);
                    size--;
                }
                bhnd = curr;
                curr = curr->getNext();
            }
        }
    }

/**
 * Finds a certain value in the list
 * @tparam T Any value desired
 * @param value value to look for
 * @return returns the node with the found value
 */
template <class T>
    T* LinkedList<T>::search(T value){
        Node<T>* curr = first;
        while(curr != NULL){
            if(curr->getData() == value) return curr;
            curr = curr->getNext();
        }
        return NULL;
    }

template <class T>
void LinkedList<T>::run(){
    Node<T>* curr = first;
    while(curr != NULL){
        curr = curr->getNext();
    }
}

template <class T>
bool LinkedList<T>::empty() {
    return (first == NULL);
}

template <class T>
void LinkedList<T>::sort(){
    int i, j;
    for (i = 0; i < size-1; i++){
        for (j = 0; j < size-i-1; j++){
            if (get(j)->getData()>get(j+1)->getData())
                swap(get(j-1),get(j), get(j+1));
            }
    }

}

template <class T>
T* LinkedList<T>::get(int n){
    Node<T>* curr = first;
    for(int i =0;i<n && curr != NULL;i++){
        curr = curr->getNext();
    }
    return curr;
}

template <class T>
void LinkedList<T>::swap(Node<T>* b4,Node<T>* x, Node<T>* y){
    if(x->getData() == first->getData()){
        x->setNext(y->getNext());
        y->setNext(x);
        first = y;
    }else{
    b4->setNext(y);
    x->setNext(y->getNext());
    y->setNext(x);}
    if(y->getData() == last->getData())
        last = x;
}

template <class T>
int LinkedList<T>::getSize() {
    return size;
}
