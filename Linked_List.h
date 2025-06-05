//
// Created by eyadd on 2025-04-21.
//

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
#include <iostream>


template <class t>
class Single_Linked_List {
private:
    struct node {
        t item;
        node* next;
    };
    node* head;
    node* tail;
    unsigned long long length;
public:
    Single_Linked_List(): head(nullptr), tail(nullptr), length(0){}

    [[nodiscard]] bool empty() const {
        return length == 0;
    }

    [[nodiscard]] unsigned long long get_length() const {
        return length;
    }

    void push_back(t new_item) {
        if (empty()) {
            tail = new node;
            tail -> item = new_item;
            tail -> next = nullptr;
            head = tail;
            ++length;
        }
        else {
            node* temp = new node;
            temp -> item = new_item;
            temp -> next = nullptr;
            tail -> next = temp;
            tail = temp;
            ++length;
        }
    }

    void push_front(t new_item) {
        if (empty()) {
            head = new node;
            head -> item = new_item;
            head -> next = nullptr;
            tail = head;
            ++length;
        }
        else {
            node* temp = new node;
            temp -> item = new_item;
            temp -> next = head;
            head = temp;
            ++length;
        }
    }

    void insert(unsigned long long index, t new_item) {
        if (index <= length) {
            if (index == 0) {
                push_front(new_item);
            }
            else if (index == length) {
                push_back(new_item);
            }
            else {
                node* new_node = new node;
                node* temp = head;
                new_node -> item = new_item;

                while (--(index)) {
                    temp = temp -> next;
                }
                new_node -> next = temp -> next;
                temp -> next = new_node;
                ++length;
            }
        }
        else {
            std::cout << "Linked List Index is out of Range at Insert" << std::endl;
        }
    }

    void print() {
        node* temp = head;
        std::cout << "[ ";
        while (temp != nullptr) {
            std::cout << temp -> item << ' ';
            temp = temp -> next;
        }
        std::cout << ']' << std::endl;
        delete temp;
    }

    void pop_front() {
        if (!empty()) {
            const node* temp = head;
            head = head -> next;
            delete temp;
            --length;
        }
        else {
            std::cout << "Linked List is empty at Pop Front" << std::endl;
        }
    }

    void pop_back() {
        if (!empty()) {
            node* temp = head;
            while (temp -> next -> next != nullptr) {
                temp = temp -> next;
            }
            tail = temp;
            temp = temp -> next;
            tail -> next = nullptr;
            delete temp;
            --length;
        }
        else {
            std::cout << "Linked List is empty at Pop Back" << std::endl;
        }
    }

    void erase(long long index) {
        if (index >= 0 && index < length) {
            if (index == 0) {
                pop_front();
            }
            else if (index == (length - 1)) {
                pop_back();
            }
            else {
                node* temp = head;
                while (--index) {
                    temp = temp -> next;
                }
                node* del = temp -> next;
                temp -> next = del -> next;
                delete del;
                --length;
            }
        }
        else {
            std::cout << "Linked List Index is out of Range in erase" << std::endl;
        }
    }

    void reverse() {
        node *prevptr = nullptr;
        node *currptr = head;

        while (currptr != nullptr) {
            node *nextptr = currptr->next;
            currptr -> next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        head = prevptr;
    }

    unsigned long long find (t item) {
        node* temp = head;
        unsigned long long index = 0;
        while (temp != nullptr) {
            if (temp -> item == item) return index;
            temp = temp -> next;
            ++index;
        }
    }
};



#endif //SINGLE_LINKED_LIST_H