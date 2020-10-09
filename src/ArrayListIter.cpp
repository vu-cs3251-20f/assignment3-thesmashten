//
// Created by Nishant Jain on 10/8/20.
//
#ifndef ARRAYLISTITER_CPP
#define ARRAYLISTITER_CPP
#include "ArrayList.h"

template <typename T>
bool ArrayListIterator<T> ::operator==(const ArrayListIterator<T> &rhs) const{
    return mPtr == rhs.mPtr;
}

template <typename T>
bool ArrayListIterator<T> :: operator!=(const ArrayListIterator<T>& rhs) const{
    return !(*this == rhs);
}

template <typename T>
T& ArrayListIterator<T> :: operator*(){
    return *mPtr;
}

template <typename T>
const T& ArrayListIterator<T> :: operator*() const{
    return *mPtr;
}

template <typename T>
T* ArrayListIterator<T> :: operator->(){
    return mPtr;
}

template <typename T>
const T* ArrayListIterator<T> :: operator->() const{
    return mPtr;
}

template <typename T>
ArrayListIterator<T>& ArrayListIterator<T> :: operator++(){
    ++mPtr;
    return *this;
}

/**
* Predecrement operator.
* @return *this after the decrement.
*/
template <typename T>
ArrayListIterator<T>& ArrayListIterator<T> :: operator--(){
    --mPtr;
    return *this;
}


/**
 * Postincrement operator.
 * @return The iterator before the increment.
 */
template <typename T>
ArrayListIterator<T> ArrayListIterator<T> :: operator++(int32_t){
    ArrayListIterator<T> tmp(*this);
    ++mPtr;
    return tmp;
}

/**
 * Postdecrement operator.
 * @return The iterator before the decrement.
 */
template <typename T>
ArrayListIterator<T> ArrayListIterator<T> :: operator--(int32_t){
    ArrayListIterator<T> tmp(*this);
    --mPtr;
    return tmp;
}

/**
 * Returns an iterator offset elements forward
 * @param offset distance to move forward
 * @return the moved iterator.
 */
template <typename T>
ArrayListIterator<T> ArrayListIterator<T> :: operator+(int32_t offset) const{
    return ArrayListIterator<T>(mPtr + offset);
}
/**
 * Returns an iterator offset elements backwards
 * @param offset distance to move back
 * @return the moved iterator.
 */
template <typename T>
ArrayListIterator<T> ArrayListIterator<T> :: operator-(int32_t offset) const{
    return ArrayListIterator<T>(mPtr - offset);
}

/**
 * Iterator subtraction (equivalent to pointer subtraction).
 *
 * @param rhs Iterator to subtract
 * @return distance between iterators
 */
template <typename T>
int32_t ArrayListIterator<T> :: operator-(const ArrayListIterator<T>& rhs) const{
    return (int)(mPtr - rhs.mPtr);
}

/**
 * Subscript operator.
 * @param index offset from current position.
 * @return the const reference to the value at the index offset from *this.
 */
template <typename T>
const T& ArrayListIterator<T> :: operator[](const int32_t index) const{
    for (int i = 0; i < index; ++i){
        ++mPtr;
    }
    const ArrayListIterator<T> tmp(*this);
    return &tmp;
}




#endif