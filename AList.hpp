#ifndef ALIST_HPP
#define ALIST_HPP

#include "anode.hpp"
using namespace std;

template <class T>
class AList {
private:
    ANode<T>* first;
    ANode<T>* last;
    int numNodes;

    //to limit the recursion necessary if get is invoked by a for loop
    ANode<T>* currentNode;
    int currentNodeIter;

    //while loop with get next
    ANode<T>* whileNode;

    T getRecursion(int, int);

public:
    AList();
    AList(T);
    AList(const AList<T>&);
    void add(T);
    int getSize();
    T get(int);

    //gets when known item
    T getPrevious(T);
    T getNext(T);

    //gets based on whileNode
    T getPrevious();
    T getNext();

    bool inList(T);
    void clear();
    //distincition incase type of list is int
    void deleteByData(T);
    void deleteByIndex(int);
    ~AList();
};

#endif

template <class T>
AList<T>::AList() {
    first = nullptr;
    last = nullptr;
    numNodes = 0;
    currentNode = nullptr;
    whileNode = nullptr;
    currentNodeIter = 0;
}

template <class T>
AList<T>::AList(T data) {
    first = new ANode<T>(data);
    last = first;
    numNodes = 1;
    currentNode = nullptr;
    whileNode = first;
    currentNodeIter = 0;
}

template <class T>
AList<T>::AList(const AList<T>& data) {
    first = new ANode<T>(data.first->getData());
    numNodes = 1;
    last = first;

    //start at 1 since first has already been assigned
    //add changes where last is pointing
    ANode<T>* tempNode = data.first->getNext();
    for (int i = 1; i < data.numNodes; i++) {
        T temp = tempNode->getData();
        add(temp);
        if (tempNode->getNext() != nullptr)
            tempNode = tempNode->getNext();
    }
    currentNode = nullptr;
    whileNode = first;
    currentNodeIter = 0;
}

template <class T>
void AList<T>::add(T data) {
    ANode<T>* temp = new ANode<T>(data);
    //if first node
    if (first == nullptr) {
        first = temp;
        last = temp;
    }
    else {
        //set previous last to point to temp
        last->setNext(temp);
        //set temp to point back to last
        temp->setPrevious(last);
        //now reset last to the new value
        last = temp;
    }
    numNodes++;
}

template <class T>
int AList<T>::getSize() {
    return numNodes;
}

template <class T>
T AList<T>::get(int index) {
    try {
        //check to see if stored iteration is pointing to the correct node
        if (index == currentNodeIter && currentNode != nullptr) {
            return currentNode->getData();
        }
        else {
            //if no node stored, or if looking for earlier node
            //start from the beginning
            if (currentNode == nullptr || index < currentNodeIter) {
                currentNode = first;
                return getRecursion(index, 0);
            }
            else {
                //if index is after stored, start searching from stored
                return getRecursion(index, currentNodeIter);
            }
        }
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
}

template <class T>
T AList<T>::getRecursion(int index, int currentIndex) {
    try {
        if (index == currentIndex) {
            currentNodeIter = index;
            return currentNode->getData();
        }
        else {
            currentIndex++;
            currentNode = currentNode->getNext();
            return getRecursion(index, currentIndex);
        }
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
}

//get previous of known data
template <class T>
T AList<T>::getPrevious(T data) {
    try {
        for (int i = 0; i < numNodes; i++) {
            if (data == get(i)) {
                return currentNode->getPrevious()->getData();
                break;
            }
            else if (i == numNodes - 1) {
                //Reached end of list without finding data
                AString except("Data not stored in list");
                throw except;
            }
        }
    }
    catch (AString e) {
        cout << e << endl;
    }
}

//get next of known data
template <class T>
T AList<T>::getNext(T data) {
    try {
        for (int i = 0; i < numNodes; i++) {
            if (data == get(i)) {
                return currentNode->getNext()->getData();
                break;
            }
            else if (i == numNodes - 1) {
                //Reached end of list without finding data
                AString except("Data not stored in list");
                throw except;
            }
        }
    }
    catch (AString e) {
        cout << e << endl;
    }
}

template <class T>
T AList<T>::getPrevious() {
    //move back along the list until you hit the first one
    try {
        whileNode = whileNode->getPrevious();
        return whileNode->getData();
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
}

template <class T>
T AList<T>::getNext() {
    //move back along the list until you hit the last one
    try {
        whileNode = whileNode->getNext();
        return whileNode->getData();
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

}

template <class T>
bool AList<T>::inList(T data) {
    bool found = false;
    for (int i = 0; i < numNodes; i++) {
        if (data == get(i)) {
            found = true;
        }
    }
    return found;
}

template <class T>
void AList<T>::deleteByData(T data) {
    for (int i = 0; i < numNodes; i++) {
        if (data == get(i)) {
            //currentNode will now be pointing to the node that will be deleted
            ANode<T>* prev = currentNode->getPrevious();
            ANode<T>* next = currentNode->getNext();
            //have the prev and next point to eachother
            if (prev != nullptr)
                prev->setNext(next);
            if (next != nullptr)
                next->setPrevious(prev);
            if (currentNode == last)
                last = prev;
            if (currentNode == first) {
                first = next;
                whileNode = first;
            }
            //memory management
            delete currentNode;
            currentNode = nullptr;
            currentNodeIter = 0;
            numNodes--;
            break;
        }
        else if (i == numNodes - 1) {
            //Reached end of list without finding data
            std::cout << "Data not stored in list. Nothing deleted." << std::endl;
        }
    }
}

template <class T>
void AList<T>::deleteByIndex(int index) {
    if (index >= numNodes) {
        std::cout << "Index " << index << " is out of bounds, no node deleted." << std::endl;
    }
    else {
        get(index);
        //currentNode will now be pointing to the node that will be deleted
        ANode<T>* prev = currentNode->getPrevious();
        ANode<T>* next = currentNode->getNext();
        //have the prev and next point to eachother
        if (prev != nullptr)
            prev->setNext(next);
        if (next != nullptr)
            next->setPrevious(prev);
        //memory management
        if (currentNode == last)
            last = prev;
        if (currentNode == first) {
            first = next;
            whileNode = first;
        }
        delete currentNode;
        numNodes--;
        currentNode = nullptr;
        currentNodeIter = 0;
    }
}

template <class T>
void AList<T>::clear() {
    ANode<T>* current = last;
    ANode<T>* prev;
    //delete every node, starting from the end
    while (current != nullptr) {
        prev = current->getPrevious();
        delete current;
        current = prev;
    }
    first = nullptr;
    last = nullptr;
    currentNode = nullptr;
    whileNode = nullptr;
    numNodes = 0;
}

template <class T>
AList<T>::~AList() {
    ANode<T>* current = last;
    ANode<T>* prev;
    //delete every node, starting from the end
    while (current != nullptr) {
        prev = current->getPrevious();
        delete current;
        current = prev;
    }
    first = nullptr;
    last = nullptr;
    currentNode = nullptr;
    whileNode = nullptr;
    numNodes = 0;
}
