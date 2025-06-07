//
// Created by eyadd on 2025-05-02.
// Corrected and reviewed version.
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdexcept> // For std::out_of_range
#include <iostream>  // For the print() method

template <class t>
class Doubly_Linked_List {
private:
    struct node {
        node* next;
        node* prev;
        t item;
    };
    node* front;
    node* back;
    unsigned long long length;

public:
    // Default constructor
    Doubly_Linked_List(): front(nullptr), back(nullptr), length(0) {}

    // Copy constructor
    Doubly_Linked_List(const Doubly_Linked_List& other) : front(nullptr), back(nullptr), length(0) {
        // Creates a deep copy of the other list
        node* temp = other.front;
        while (temp != nullptr) {
            this -> push_back(temp -> item);
            temp = temp->next;
        }
    }

    // Copy assignment operator
    Doubly_Linked_List& operator = (const Doubly_Linked_List& other) {
        // Check for self-assignment
        if (this == &other) {
            return *this;
        }

        // Clear the current list to prevent memory leaks
        this->clear();

        // Copy elements from the other list
        node* temp = other.front;
        while (temp != nullptr) {
            this -> push_back (temp -> item);
            temp = temp -> next;
        }

        return *this;
    }

    // Destructor
    ~Doubly_Linked_List() {
        clear();
    }

    [[nodiscard]] unsigned long long get_length() const {
        return length;
    }

    [[nodiscard]] bool empty() const {
        return length == 0;
    }

    void push_back(t new_item) {
        node* new_node = new node{nullptr, nullptr, new_item};
        if (empty()) {
            front = new_node;
            back = new_node;
        }
        else {
            back->next = new_node;
            new_node->prev = back;
            back = new_node;
        }
        ++length;
    }

    void push_front (t new_item) {
        node* new_node = new node{nullptr, nullptr, new_item};
        if (empty()) {
            front = new_node;
            back = new_node;
        }
        else {
            front->prev = new_node;
            new_node->next = front;
            front = new_node;
        }
        ++length;
    }

    void insert(const unsigned long long index, t new_item) {
        if (index > length) {
            throw std::out_of_range("Index out of range in insert()");
        }

        if (index == 0) {
            push_front(new_item);
        }
        else if (index == length) {
            push_back(new_item);
        }
        else {
            node* temp;
            // Optimization: traverse from the end that is closer to the index
            if (index <= length / 2) {
                temp = front;
                for (unsigned long long i = 0; i < index; ++i) {
                    temp = temp -> next;
                }
            }
            else {
                temp = back;
                for (unsigned long long i = length - 1; i > index; --i) {
                    temp = temp -> prev;
                }
            }

            node* new_node = new node;
            new_node->item = new_item;
            new_node->next = temp;
            new_node->prev = temp->prev;
            temp->prev->next = new_node;
            temp->prev = new_node;

            ++length;
        }
    }

    void pop_back() {
        if (empty()) return;
        node* temp = back;
        if (front == back) {  // only one element
            front = back = nullptr;
        } else {
            back = back->prev;
            back->next = nullptr;
        }
        delete temp;
        --length;
    }

    void pop_front() {
        if (empty()) return;
        node* temp = front;
        if (front == back) {  // only one element
            front = back = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        --length;
    }


    void erase (unsigned long long index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range in erase()");
        }

        if (index == 0) {
            pop_front();
            return;
        }
        if (index == (length - 1)) {
            pop_back();
            return;
        }

        node* temp;
        // Optimization: traverse from the end that is closer to the index
        if (index <= (length / 2)) {
            temp = front;
            for (unsigned long long i = 0; i < index; ++i) {
                temp = temp -> next;
            }
        }
        else {
            temp = back;
            for (unsigned long long i = (length - 1); i > index; --i) {
                temp = temp -> prev;
            }
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        --length;
    }

    void clear() {
        node* current = front;
        while (current != nullptr) {
            node* next_node = current->next;
            delete current;
            current = next_node;
        }
        front = back = nullptr;
        length = 0;
    }

    // FIX: The original implementation did not correctly swap the pointers.
    void reverse() {
        if (empty() || length == 1) {
            return;
        }

        node* current = front;
        node* temp_ptr = nullptr;

        // Iterate through the list and swap the next and prev pointers for each node
        while (current != nullptr) {
            temp_ptr = current->prev;       // Store the original previous pointer
            current->prev = current->next;  // The new prev is the original next
            current->next = temp_ptr;       // The new next is the original prev
            current = current->prev;        // Move to the next node (which is the original next)
        }

        // After swapping all pointers, swap the main front and back pointers of the list.
        // The original front's prev pointer (which is now in `temp_ptr`) is the new head.
        if (temp_ptr != nullptr) {
             front = temp_ptr->prev;
        }

        // A simpler way to swap front and back after the pointer surgery:
        temp_ptr = front;
        front = back;
        back = temp_ptr;
    }

    void print() const {
        node* temp = front;
        std::cout << "[ ";
        while (temp != nullptr) {
            std::cout << temp -> item << ' ';
            temp = temp -> next;
        }
        std::cout << ']' << std::endl;
    }

    class iterator {
    private:
        node* curr;
        // Private constructor so only the list class can create iterators
        iterator(node* p) : curr(p) {}

    public:
        // Make the list class a friend to allow access to the private constructor
        friend class Doubly_Linked_List<t>;

        iterator(): curr(nullptr) {}
        iterator(const iterator& other): curr(other.curr) {}

        iterator& operator = (const iterator& other) {
            if (this != &other) {
                curr = other.curr;
            }
            return *this;
        }

        bool operator == (const iterator& other) const {
            return curr == other.curr;
        }

        bool operator != (const iterator& other) const {
            return curr != other.curr;
        }

        t& operator* () {
            if (curr) {
                return curr->item;
            }
            throw std::runtime_error("Dereferencing a null iterator.");
        }

        // Pre-increment
        iterator& operator ++ () {
            if (curr) {
                curr = curr->next;
            }
            return *this;
        }

        // Post-increment
        iterator operator ++ (int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        // Pre-decrement
        iterator& operator -- () {
            if (curr) {
                curr = curr->prev;
            }
            return *this;
        }

        // Post-decrement
        iterator operator -- (int) {
            iterator temp = *this;
            --(*this);
            return temp;
        }
    };

    iterator begin() {
        return iterator(front);
    }

    iterator end() {
        // end() is one position past the last element, which is represented by nullptr
        return iterator(nullptr);
    }

};



#endif //DOUBLY_LINKED_LIST_H
