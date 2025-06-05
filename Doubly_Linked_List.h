//
// Created by eyadd on 2025-05-02.
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

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
    Doubly_Linked_List(): front(nullptr), back(nullptr), length(0) {}

    Doubly_Linked_List(const Doubly_Linked_List& other) : front(nullptr), back(nullptr), length(0) {
        node* temp = other.front;
        while (temp != nullptr) {
            this -> push_back(temp -> item);
            temp = temp->next;
        }
    }

    Doubly_Linked_List& operator = (const Doubly_Linked_List& other) {
        if (this == &other) {
            return *this;
        }

        node* current = front;
        while (current != nullptr) {
            node* next_node = current->next;
            delete current;
            current = next_node;
        }

        front = nullptr;
        back = nullptr;
        length = 0;

        node* temp = other.front;
        while (temp != nullptr) {
            this -> push_back (temp -> item);
            temp = temp -> next;    
        }

        return *this;
    }


    [[nodiscard]] unsigned long long get_length() const {
        return length;
    }

    [[nodiscard]] bool empty() const {
        return length == 0;
    }

    void push_back(t new_item) {
        if (empty()) {
            back = new node;
            back -> item = new_item;
            back -> next = nullptr;
            back -> prev = nullptr;
            front = back;
            ++length;
        }
        else {
            node* temp = new node;
            temp -> item = new_item;
            temp -> prev = back;
            temp -> next = nullptr;
            back -> next = temp;
            back = temp;
            ++length;
        }
    }

    void push_front (t new_item) {
        if (empty()) {
            front = new node;
            front -> item = new_item;
            front -> next = nullptr;
            front -> prev = nullptr;
            back = front;
            ++length;
        }
        else {
            node* temp = new node;
            temp -> item = new_item;
            temp -> next = front;
            temp -> prev = nullptr;
            front -> prev = temp;
            front = temp;
            ++length;
        }
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
            new_node -> item = new_item;
            new_node -> next = temp;
            new_node -> prev = temp->prev;
            temp -> prev -> next = new_node;
            temp -> prev = new_node;

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
            throw std::out_of_range("Index out of range in insert()");
        }

        if (index == 0) {
            pop_front();
        }
        else if (index == (length - 1)) {
            pop_back();
        }
        else {
            if (index <= (length / 2)) {
                node* temp = front;
                for (unsigned long long i = 0; i < index; ++i) {
                    temp = temp -> next;
                }
                temp -> next ->prev = temp -> prev;
                temp -> prev -> next = temp -> next;
                delete temp;
                --length;
            }
            else {
                node* temp = back;
                for (unsigned long long i = (length - 1); i > index; --i) {
                    temp = temp -> prev;
                }
                temp -> next ->prev = temp -> prev;
                temp -> prev -> next = temp -> next;
                delete temp;
                --length;
            }
        }
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void reverse() {
        node* temp = back;
        back = front;
        front = temp;

        while (temp != nullptr) {
            node* prev_node = temp -> prev;
            temp -> next = temp -> prev;
            temp -> prev  = prev_node;
            temp = prev_node;
        }
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

    ~Doubly_Linked_List() {
        node* current = front;
        while (current != nullptr) {
            node* next_node = current->next;
            delete current;
            current = next_node;
        }
    }

}; 



#endif //DOUBLY_LINKED_LIST_H