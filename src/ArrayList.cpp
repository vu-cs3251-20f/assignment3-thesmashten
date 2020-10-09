//
// Created by Nishant Jain on 10/8/20.
//
#ifndef ARRAYLIST_CPP
#define ARRAYLIST_CPP

#include <cstdint>



/**
 * Creates an ArrayList of size 0.
 */
template <typename T>
ArrayList<T> :: ArrayList() : mArray(), mSize(0), mCapacity(0) {}


/**
 * Creates an ArrayList of the provided size and fills it with the provided
 * value - default to the default value of the template type.
 * @param size size of the ArrayList to create
 * @param value value used to fill the ArrayList
 */
template <typename T>
ArrayList<T> :: ArrayList(const uint32_t size, const T& value) :
    mArray(new T [size]), mSize(size), mCapacity(size){
    for (uint32_t i = 0; i < mCapacity; ++i){
        mArray[i]  = value;
    }
}


/**
 * Creates a deep copy of the provided ArrayList
 * @param src ArrayList to copy
 */
template <typename T>
ArrayList<T> :: ArrayList(const ArrayList<T> &src) : mArray(new T[src.size()]),
    mSize(src.size()), mCapacity(src.mCapacity){
    std :: copy(src.begin(), src.end(), begin());
}


/**
 * Makes *this a deep copy of the provided ArrayList.
 * @param src ArrayList to copy
 * @return *this for chaining
 */
template <typename T>
ArrayList<T> &ArrayList<T> ::operator=(const ArrayList<T>& rhs) {
    if (this != &rhs) {
        ScopedArray<T> temp(new T[rhs.mSize]);
        for (uint32_t i = 0; i < rhs.mSize; ++i) {
            temp[i] = rhs.mArray[i];
        }
        mArray.swap(temp);
        mSize = rhs.mSize;
        mCapacity = rhs.mCapacity;
    }
    return *this;
}


/**
 * Adds the provided element to the end of this ArrayList.  If the ArrayList needs to be
 * enlarged, double the capacity from the current capacity, or go from zero to one.
 * @param value value to add
 * @return total array capacity
 */
template <typename T>
uint32_t ArrayList<T> :: add(const T& value){
    return add(0, value);
}

/**
 * Inserts the specified value into this ArrayList at the specified index.
 * The object is inserted before any previous element at the specified
 * location. If the ArrayList needs to be enlarged, continue doubling the capacity
 * from the current capacity until the desired index is in range.  Fill any empty
 * elements up to the new element's index with the default value for the template type.
 * @param index location at which to insert the new element
 * @param value the element to insert
 * @return total array capacity
 */
template <typename T>
uint32_t ArrayList<T> :: add(const uint32_t index, const T& value){
    if (mSize == 0){
        ScopedArray<T> tmp(new T[1]);
        mArray.swap(tmp);
        ++mCapacity;
    }
    else if (index >= mCapacity){
        uint32_t newCap = mCapacity * 2;
        while (index > newCap){
            newCap *= 2;
        }
        ScopedArray<T> tmp(new T[newCap]);
        for (uint32_t i = 0; i < index; ++i){
            tmp[i] = mArray[i];
        }
        for (uint32_t i = mSize; i < index; ++i){
            tmp[i] = value;
            ++mSize;
        }
        mArray.swap(tmp);
        mCapacity = newCap;
    }
    return mCapacity;
}

/**
 * Clears this ArrayList, leaving it empty.
 */
template <typename T>
void ArrayList<T> :: clear(){
    for (uint32_t i = 0; i < mCapacity; ++i){
        mArray[i] = T();
    }
    mSize = mCapacity = 0;
}


/**
 * Removes an element at the specified location from this ArrayList and
 * returns it. Elements following index are shifted down. If index is out of
 * range, std::out_of_range is thrown with index as its message.
 * @param index the desired location
 * @return a copy of the removed element.
 */

template <typename T>
T ArrayList<T> :: remove(const uint32_t index){
    if (index > mCapacity){
        throw std::out_of_range("Out of range.");
    }
    T tmp (mArray[index]);
    for (uint32_t i = index; i < mCapacity - 1; ++i){
        mArray[i + 1] = mArray[i];
    }
    --mSize;
    return tmp;
}


/**
 * Sets the element at the desired location to the specified value. If index
 * is out of range, std::out_of_range is thrown with index as its message.
 * @param index the location to change
 * @param value the new value of the specified element.
 */
template <typename T>
void ArrayList<T> :: set(const uint32_t index, const T& value){
    if (index >= mCapacity){
        throw std::out_of_range("Out of range.");
    }
    mArray[index] = value;
}


/**
 * Returns the size of this ArrayList.
 * @return the size of this ArrayList.
 */
template <typename T>
uint32_t ArrayList<T> :: size() const{
    return mSize;
}

/**
 * Empty check.
 * @return True if this ArrayList is empty and false otherwise.
 */
template <typename T>
bool ArrayList<T> :: isEmpty() const{
    return mSize == 0;
}

/**
 * Returns a const T & to the element stored at the specified index.
 * If the index is out of bounds, std::out_of_range is thrown with the index
 * as its message.
 * @param index the desired location
 * @return a const T & to the desired element.
 */
template <typename T>
const T& ArrayList<T> :: get(const uint32_t index) const{
    if (index > mCapacity){
         throw std::out_of_range("Out of exception.");
    }
    return mArray[index];
}

/**
 * Returns a T & to the element stored at the specified index.
 * If the index is out of bounds, std::out_of_range is thrown with the index
 * as its message.
 * @param index the desired location
 * @return a T & to the desired element.
 */
template <typename T>
T& ArrayList<T> :: get(const uint32_t index){
    if (index > mCapacity){
        throw std::out_of_range("Out of exception.");
    }
    return const_cast<T&>(const_cast<const ArrayList&>(*this)[index]);
}

/**
 * Returns a T & to the element stored at the specified index.
 * No range checking is performed.
 * Must call to the const operator[] - do not reimplement logic!
 * @param index the desired location
 * @return a T & to the desired element.
 */
template <typename T>
T& ArrayList<T> :: operator[](const uint32_t index){
    return const_cast<T&>(const_cast<const ArrayList&>(*this)[index]);
}

/**
 * Returns a const T & to the element stored at the specified index.
 * No range checking is performed.
 * @param index the desired location
 * @return a const T & to the desired element.
 */
template <typename T>
const T& ArrayList<T> :: operator[](const uint32_t index) const{
    return mArray[index];
}

/**
 * Returns const iterator to the beginning; in this case, a random access
 * iterator
 * @return an const iterator to the beginning of this ArrayList.
 */
template <typename T>
ArrayListIterator<T> ArrayList<T> ::begin(){
    return ArrayListIterator<T>(mArray.get());
}

/**
 * Returns the past-the-end iterator of this ArrayList.
 * @return a past-the-end iterator of this ArrayList.
 */
template <typename T>
ArrayListIterator<T> ArrayList<T>::end() {
    T* ptr = mArray.get() + mSize;
    return ArrayListIterator<T>(ptr);
}

/**
 * Preincrement operator.
 * @return *this after the increment.
 */
template <typename T>
ArrayListConstIterator<T>
#endif