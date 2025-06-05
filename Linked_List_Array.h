//
// Created by eyadd on 2025-04-21.
//

#ifndef LINKED_LIST_ARRAY_H
#define LINKED_LIST_ARRAY_H
#include <iostream>
using namespace std;


template <class t>
class Array {
    int max_size;
    int* arr;
    int length;
public:
    Array(size_t size):max_size(size), arr(new t), length(0) {}

    bool empty() {
        return length ==0;
    }

    bool full() {
        return length == max_size;
    }

    int get_length() {
        return length;
    }

    void print() const {
        cout << "[ ";
        for (size_t i = 0; i < length; ++i) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }

    void push_back (t value) {
        if (!full()) {
            arr[length] = value;
            ++length;
        }
        else {
            cout << "Array is full at Push Back" << endl;
        }
    }

    void push_front (t value) {
        if (!full()) {
            for (size_t i = length; i > 0; --i) {
                arr[i] = arr[i - 1];
            }
            arr[0] = value;
            ++length;
        }
        else {
            cout << "Array is full at Push Front" << endl;
        }
    }

    void insert (size_t pos, t value) {
        if (!full() && pos <= length ) {
            for (size_t i = length; i > pos; --i) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = value;
            ++length;
        }
        else if (pos > length) {
            cout << "Out of range in Insert" << endl;
        }
        else {
            cout << "Array is full at Insert" << endl;
        }
    }

    void erase(size_t pos) {
        if (!empty() && pos <= length ) {
            for (size_t i = pos; i < length; ++i) {
                arr[i] = arr[i + 1];
            }
            --length;
        }
        else if (pos > length) {
            cout << "Out of range in Insert At" << endl;
        }
        else {
            cout << "Array is empty at Insert At" << endl;
        }
    }

    t at(size_t pos) {
        if (!empty() && pos < length) {
            return arr[pos];
        }
        cout << "Out of range in Insert At" << endl;
    }

    void update_at (size_t pos, t val) {
        if (!full() && pos <= length ) {
            arr[pos] = val;
        }
        else {
            cout << "Out of range in Insert At" << endl;
        }
    }

    void clear() {
        length = 0;
    }

    ~Array() {
        delete[] arr;
    }
};



#endif //LINKED_LIST_ARRAY_H
