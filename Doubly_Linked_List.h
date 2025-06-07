/**
 * @file Doubly_Linked_List.h
 * @brief A template-based implementation of a doubly linked list with bidirectional traversal
 * @author Eyadd
 * @date 2025-05-02
 * @version 2.0
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdexcept> // For std::out_of_range
#include <iostream>  // For the print() method
#include <iterator>

/**
 * @brief A template-based doubly linked list implementation
 * @tparam T The type of elements stored in the list
 */
template <class T>
class Doubly_Linked_List {
private:
    /**
     * @brief Node structure for the doubly linked list
     */
    struct Node {
        Node* next;
        Node* prev;
        T item;

        explicit Node(const T& value) : next(nullptr), prev(nullptr), item(value) {}
        explicit Node(T&& value) : next(nullptr), prev(nullptr), item(std::move(value)) {}
    };

    Node* front;
    Node* back;
    size_t length;

public:
    // Type definitions for STL compatibility
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;

    /**
     * @brief Default constructor
     */
    Doubly_Linked_List() noexcept : front(nullptr), back(nullptr), length(0) {}

    /**
     * @brief Copy constructor
     * @param other The list to copy from
     */
    Doubly_Linked_List(const Doubly_Linked_List& other) : front(nullptr), back(nullptr), length(0) {
        Node* temp = other.front;
        while (temp != nullptr) {
            push_back(temp->item);
            temp = temp->next;
        }
    }

    /**
     * @brief Move constructor
     * @param other The list to move from
     */
    Doubly_Linked_List(Doubly_Linked_List&& other) noexcept 
        : front(other.front), back(other.back), length(other.length) {
        other.front = nullptr;
        other.back = nullptr;
        other.length = 0;
    }

    /**
     * @brief Copy assignment operator
     * @param other The list to copy from
     * @return Reference to this list
     */
    Doubly_Linked_List& operator=(const Doubly_Linked_List& other) {
        if (this != &other) {
            clear();
            Node* temp = other.front;
            while (temp != nullptr) {
                push_back(temp->item);
                temp = temp->next;
            }
        }
        return *this;
    }

    /**
     * @brief Move assignment operator
     * @param other The list to move from
     * @return Reference to this list
     */
    Doubly_Linked_List& operator=(Doubly_Linked_List&& other) noexcept {
        if (this != &other) {
            clear();
            front = other.front;
            back = other.back;
            length = other.length;
            other.front = nullptr;
            other.back = nullptr;
            other.length = 0;
        }
        return *this;
    }

    /**
     * @brief Destructor
     */
    ~Doubly_Linked_List() {
        clear();
    }

    /**
     * @brief Get the current length of the list
     * @return The number of elements in the list
     */
    [[nodiscard]] size_t size() const noexcept {
        return length;
    }

    /**
     * @brief Check if the list is empty
     * @return true if the list is empty, false otherwise
     */
    [[nodiscard]] bool empty() const noexcept {
        return length == 0;
    }

    /**
     * @brief Add an element to the end of the list
     * @param value The value to add
     */
    void push_back(const T& value) {
        Node* new_node = new Node(value);
        if (empty()) {
            front = back = new_node;
        } else {
            back->next = new_node;
            new_node->prev = back;
            back = new_node;
        }
        ++length;
    }

    /**
     * @brief Add an element to the end of the list using move semantics
     * @param value The value to add
     */
    void push_back(T&& value) {
        Node* new_node = new Node(std::move(value));
        if (empty()) {
            front = back = new_node;
        } else {
            back->next = new_node;
            new_node->prev = back;
            back = new_node;
        }
        ++length;
    }

    void push_front (T new_item) {
        Node* new_node = new Node(new_item);
        if (empty()) {
            front = back = new_node;
        }
        else {
            front->prev = new_node;
            new_node->next = front;
            front = new_node;
        }
        ++length;
    }

    void insert(const unsigned long long index, T new_item) {
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
            Node* temp;
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

            Node* new_node = new Node(new_item);
            new_node->next = temp;
            new_node->prev = temp->prev;
            temp->prev->next = new_node;
            temp->prev = new_node;

            ++length;
        }
    }

    void pop_back() {
        if (empty()) return;
        Node* temp = back;
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
        Node* temp = front;
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

        Node* temp;
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
        Node* current = front;
        while (current != nullptr) {
            Node* next_node = current->next;
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

        Node* current = front;
        Node* temp_ptr = nullptr;

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
        Node* temp = front;
        std::cout << "[ ";
        while (temp != nullptr) {
            std::cout << temp -> item << ' ';
            temp = temp -> next;
        }
        std::cout << ']' << std::endl;
    }

    /**
     * @brief Iterator class for the doubly linked list
     */
    class Iterator {
    private:
        Node* current;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit Iterator(Node* node = nullptr) : current(node) {}

        reference operator*() {
            if (!current) throw std::runtime_error("Dereferencing null iterator");
            return current->item;
        }

        pointer operator->() {
            if (!current) throw std::runtime_error("Dereferencing null iterator");
            return &(current->item);
        }

        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            if (current) current = current->next;
            return temp;
        }

        Iterator& operator--() {
            if (current) current = current->prev;
            return *this;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            if (current) current = current->prev;
            return temp;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    /**
     * @brief Get an iterator to the beginning of the list
     * @return Iterator pointing to the first element
     */
    Iterator begin() {
        return Iterator(front);
    }

    /**
     * @brief Get an iterator to the end of the list
     * @return Iterator pointing past the last element
     */
    Iterator end() {
        // end() is one position past the last element, which is represented by nullptr
        return Iterator(nullptr);
    }

};



#endif //DOUBLY_LINKED_LIST_H
