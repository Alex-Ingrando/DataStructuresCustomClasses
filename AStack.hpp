#ifndef ASTACK_HPP
#define ASTACK_HPP

#include "alist.hpp"

template <class T>
class AStack {

private:
    AList<T> stackList;
public:
    AStack();
    AStack(const AStack<T>&);
    bool isEmpty();
    bool isIn(T);
    void push(T);
    T pop();
    T peek();
    ~AStack();
};

#endif // ASTACK_HPP

template <class T>
AStack<T>::AStack() {

}

template <class T>
AStack<T>::AStack(const AStack<T>& newData) {
    AList<T> temp(newData.stackList);
    for (int i = 0; i < temp.getSize(); i++) {
        stackList.add(temp.get(i));
    }
}

template <class T>
bool AStack<T>::isEmpty() {
    if (stackList.getSize() != 0)
        return false;
    else
        return true;
}

template <class T>
bool AStack<T>::isIn(T data) {
    return stackList.inList(data);
}

template <class T>
void AStack<T>::push(T item) {
    stackList.add(item);
}

template <class T>
T AStack<T>::pop() {
    T temp = stackList.get(stackList.getSize() - 1);
    stackList.deleteByIndex(stackList.getSize() - 1);
    return temp;
}

template <class T>
T AStack<T>::peek() {
    T temp = stackList.get(stackList.getSize() - 1);
    return temp;
}

template <class T>
AStack<T>::~AStack() {

}
