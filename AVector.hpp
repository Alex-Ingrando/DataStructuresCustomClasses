#ifndef AVECTOR_HPP
#define AVECTOR_HPP

#include <stdexcept>

template <class T>
class AVector {

private:
    int numElements;
    int cap;
    T* data;

public:
    AVector();
    AVector(int);
    AVector(AVector&);

    AVector& operator= (const AVector&);

    void increaseCapacity(int);
    void pushBack(T);
    T& at(int);
    void changeAt(T, int);
    void addAt(T, int);
    void deleteAt(int);
    int sizeVector();
    bool empty();
    void switchPlaces(int, int);
    void clear();


    ~AVector();

};

#endif

//default constructor setting number of elements to empty, and give a default capacity and initialize array;
template <class T>
AVector<T>::AVector() {
    this->cap = 10;
    this->numElements = 0;
    this->data = new T[cap];
}

//overload constructor for a unique starting capacity
template <class T>
AVector<T>::AVector(int l) {
    this->cap = l;
    this->numElements = 0;
    this->data = new T[cap];
}

template <class T>
AVector<T>::AVector(AVector& vec) {
    this->cap = vec.cap;
    this->numElements = vec.numElements;
    this->data = new T[cap];
    for (int i = 0; i < cap; i++) {
        this->data[i] = vec.data[i];
    }
}

template <class T>
AVector<T>& AVector<T>::operator= (const AVector<T>& newData) {
    this->cap = newData.cap;
    this->numElements = newData.numElements;

    if (data != nullptr) {
        delete data;
    }

    this->data = new T[cap];
    for (int i = 0; i < numElements; i++) {
        this->data[i] = newData[i];
    }
}

template <class T>
void AVector<T>::increaseCapacity(int c) {
    if (c > this->cap) {
        //store elemnts from the array that is too small
        T* temp = new T[c];
        /*T nullType{};

        for(int i = 0; i < c; i++){
            temp[i] = nullType;
        }*/
        for (int i = 0; i < this->cap; i++) {
            temp[i] = this->data[i];
        }
        delete[] data;

        //remake the array with larger values
        this->data = temp;
    }
}



template <class T>
void AVector<T>::pushBack(T type) {
    //add it to the end of the current index
    this->data[numElements] = type;

    //increase the tracker for how many elements added
    numElements++;
    //if new element excedes previously established array
    if (numElements >= cap) {
        increaseCapacity(this->cap * 2);
    }

}

//return the object correspoond to the index
template <class T>
T& AVector<T>::at(int index) {
    try {
        if (index >= numElements) {
            throw 22;
        }
    }
    catch (int ex) {
        std::cout << "Out of bounds retrieving" << std::endl;
    }
    return this->data[index];
}


//change the value at an existing index
template <class T>
void AVector<T>::changeAt(T type, int index) {
    try {
        if (index >= numElements) {
            throw 22;
        }
    }
    catch (int ex) {
        std::cout << "Out of bounds for changing" << std::endl;
    }
    this->data[index] = type;
}


template <class T>
void AVector<T>::addAt(T type, int index) {

    try {
        if (index >= numElements) {
            throw 22;
        }
    }
    catch (int ex) {
        std::cout << "Out of bounds for adding" << std::endl;
    }
    //increase the tracker for how many elements added
    numElements++;
    //if new element excedes previously established array
    if (numElements > cap) {
        increaseCapacity(this->cap * 2);
    }

    //from end of the array, start moving elements over so no new array is needed to store

    for (int i = numElements - 1; i > index; i--) {
        this->data[i] = this->data[i - 1];
    }
    this->data[index] = type;
}


template <class T>
void AVector<T>::deleteAt(int index) {
    try {
        if (index >= numElements) {
            throw 22;
        }
    }
    catch (int ex) {
        std::cout << "Out of bounds for deleting" << std::endl;
    }
    T nullType{};
    //at the deleted value, refill it with the value that came after, and continue until every element past this one has been moved back one
    for (int i = index; i < this->numElements; i++) {
        this->data[i] = this->data[i + 1];
    }
    this->data[numElements] = nullType;
    numElements--;
}


//return the number of Elements recorded
template <class T>
int AVector<T>::sizeVector() {
    return this->numElements;
}

//test if vector is empty
template <class T>
bool AVector<T>::empty() {
    bool empty = false;

    if (numElements == 0)
        empty = true;
    return empty;
}

template <class T>
void AVector<T>::switchPlaces(int pOne, int pTwo) {
    T tempOne = this->data[pOne];
    this->data[pOne] = this->data[pTwo];
    this->data[pTwo] = tempOne;
}

template <class T>
void AVector<T>::clear() {
    if (this->data != nullptr) {
        delete[] data;
        this->data = nullptr;
        this->numElements = 0;
        this->cap = 10;
        this->data = new T[cap];
    }

}


//destructor
template <class T>
AVector<T>::~AVector() {
    if (this->data != nullptr) {
        delete[] data;
    }
}

