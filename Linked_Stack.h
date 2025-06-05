//
// Created by eyadd on 2025-04-20.
//

#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <iostream>
using namespace std;

template <class t>
class Stack {
private:
    struct node {
        t item;
        node *next;
    };

    node *top;
    long long length;

public:
    Stack(): top(nullptr), length(0) {}

    void push(t new_item) {
        node *new_itemPtr = new node;

        if (new_itemPtr != nullptr) {
            new_itemPtr -> item = new_item;
            new_itemPtr -> next = top;
            top = new_itemPtr;
            ++length;
        }
        else {
            cout << "Stack push can't allocate memory" << endl;
        }
    }

    bool empty() {
        return top == nullptr;
    }

    void pop() {
        if (!empty()) {
            node *temp = top;
            top = top -> next;
            temp = temp -> next = nullptr;
            delete temp;
            --length;
        }
        else {
            cout << "Stack is empty at Stack Pop" << endl;
        }
    }

    void pop (t& item_copy) {
        if (!empty()) {
            item_copy = top -> item;
            node *temp = top;
            top = top -> next;
            temp = temp -> next = nullptr;
            delete temp;
            --length;
        }
        else {
            cout << "Stack is empty at Stack Pop" << endl;
        }
    }

    t get_top() {
        if (top != nullptr) {
            return top -> item;
        }
        else {
            cout << "Top empty at get top" << endl;
            return 0;
        }
    }

    void print() {
        node* temp = top;
        cout << "[ ";
        while (temp != nullptr) {
            cout << temp -> item << " ";
            temp = temp -> next;
        }
        cout << "]" << endl;
        delete temp;
    }

};


#endif //LINKED_STACK_H
