//
// Created by eyadd on 2025-04-20.
//

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

template <class t>
class Queue {
private:
    struct node {
        t item;
        node* next;
    };

    node* front;
    node* rear;
    long long length;

public:
    Queue(): front(nullptr), rear(nullptr), length(0) {};

    bool empty() {
        return length == 0;
    }

    void enqueue(t new_item) {
        if (empty()) {
            front = new node;
            front -> item = new_item;
            front -> next = nullptr;
            rear = front;
            ++length;
        }
        else {
            node* temp = new node;
            temp -> item = new_item;
            temp -> next = nullptr;
            rear -> next = temp;
            rear = temp;
            ++length;
        }
    }

    void dequeue () {
        if (!empty()) {
            front = front -> next;
        }
        else {
            cout << "Queue is empty at Dequeue!" << endl;
        }
    }

    void dequeue (t& val) {
        if (!empty()) {
            val = front -> item;
            node* temp = front;
            front = front -> next;
            temp -> next = nullptr;
            delete temp;
            --length;
        }
        else {
            cout << "Queue is empty at Dequeue!" << endl;
        }
    }

    void clear() {
        while (front != nullptr) {
            dequeue();
        }
        length = 0;
        rear = nullptr;
    }

    t get_front() {
        assert(!empty());
        return front -> item;
    }

    t get_rear() {
        assert(!empty());
        return rear -> item;
    }

    long long get_length () {
        return length;
    }

    void print() {
        node* temp = front;
        cout << "[ ";

        while (temp != nullptr) {
            cout << temp -> item << " ";
            temp = temp -> next;
        }
        cout << "]" << endl;
        delete temp;
    }
};



#endif //LINKED_QUEUE_H
