#ifndef ANODE_HPP
#define ANODE_HPP

#include "AString.hpp"

template <class T>
class ANode {
private:
    ANode<T>* previous;
    T data;
    ANode<T>* next;
public:
    ANode();
    ANode(const T&);
    ANode(const ANode&);
    T getData();
    void setPrevious(ANode<T>*);
    ANode<T>* getPrevious();
    void setNext(ANode<T>*);
    ANode<T>* getNext();
    ~ANode();
};

#endif

template <class T>
ANode<T>::ANode() {
    this->previous = nullptr;
    this->next = nullptr;
}

template <class T>
ANode<T>::ANode(const T& node) {
    this->previous = nullptr;
    this->next = nullptr;
    this->data = node;
}

template <class T>
ANode<T>::ANode(const ANode<T>& node) {
    this->previous = node.previous;
    this->next = node.next;
    this->data = node.data;
}

template <class T>
T ANode<T>::getData() {
    return data;
}

template <class T>
void ANode<T>::setPrevious(ANode<T>* prev) {
    this->previous = prev;
}

template <class T>
ANode<T>* ANode<T>::getPrevious() {
    return previous;
}

template <class T>
void ANode<T>::setNext(ANode<T>* nxt) {
    this->next = nxt;
}

template <class T>
ANode<T>* ANode<T>::getNext() {
    return next;
}

template <class T>
ANode<T>::~ANode() {
    previous = nullptr;
    next = nullptr;
}
