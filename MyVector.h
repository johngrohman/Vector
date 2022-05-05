#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::string;

// Purpose: Swaps two elements (including a vector).
// Parameters: a, b: the list elements themselves to be swapped
template <typename T>
void MySwap(T &a, T &b);


template <typename T>
class MyVector
{
    private:
        T *m_data = nullptr;
        int reserved_size;
        int data_size;

    public:
        // Just a simple default constructor.
        MyVector();

        ~MyVector();

        MyVector<T> & operator=(const MyVector<T> &source);

        MyVector(const MyVector<T> &source);

        // Returns the element of the array by reference, so it can be read or written.
        T & operator[](int i);

        // Purpose: Returns the element stored at the index by reference
        // Parameters: index - The location of the element to be returned.
        T & at(int index);

        // Purpose: Returns the element stored at the front of the vector
        T & front();

        // Purpose: Returns the element stored at the back of the vector
        T & back();

        // Purpose: Returns the maximum number of elements that can be stored in the current Vector
        int capacity();

        // Purpose: Ensures that there is enough room for a specific number of elements
        // Parameters: new_cap - The amount of space to be reserved in the array.
        // Postconditions: Increases max_size to new_cap if new_cap > max_size
        void reserve(int new_cap);

        void shrink_to_fit();

        // Fills the array with count of T value (e.g., 5 a would be [a, a, a, a, a])
        // This replaces the current array.
        void assign(int count, const T &value);

        // Purpose: Clears the MyVector
        // Postconditions: current size set to 0, storage size to default (0).
        //                 elements are deallocated and data is set to nullptr
        void clear();

        // Purpose: appends the value x to the end of an MyVector
        // Parameters: x is value to be added to MyVector
        // Postconditions: current size is incremented by 1
        //     If max size is reached, the storage array is grown.
        void push_back(const T &x);

        // Removes the last element of the vector
        void pop_back();

        // Purpose: inserts the value x at the position i 
        //     (before the value currently at i) in the  MyVector
        // Parameters: x is value to be added to MyVector
        //             i is the position to insert x at
        // Postconditions: current size is incremented by 1
        //     If max size is reached, the storage array is grown.
        void insert(int i, const T &x);

        // Purpose: Removes the element at index i in the array
        // Parameters: i, the index of the element to remove
        // Postconditions: if the size of the list is greater than 0
        //     size is decremented by one.
        //     if the size of the list less than 1/4 the max size,
        //     the storage array is shrunk.
        void erase(int i);

        // Returns the size of the actual data stored in the array list
        int size();
};

template <typename T>
std::ostream & operator<<(std::ostream &out, MyVector<T> &my_list)
{
    out << "[ ";

    for(int i = 0; i < my_list.size(); i++)
    {
        out << my_list.at(i) << ", ";
    }

    out << "]";

    return out;
}


#include "MyVector.hpp"

#endif

