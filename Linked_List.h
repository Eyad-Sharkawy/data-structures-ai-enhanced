/**
 * @file Linked_List.h
 * @brief A template-based implementation of a singly linked list
 * @author Eyadd
 * @date 2025-04-21
 * @version 2.0
 */

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>
#include <stdexcept>
#include <iterator>

/**
 * @brief A template-based singly linked list implementation
 * @tparam T The type of elements stored in the list
 */
template <class T>
class Single_Linked_List {
private:
    /**
     * @brief Node structure for the singly linked list
     */
    struct Node {
        T item;
        Node* next;

        explicit Node(const T& value) : item(value), next(nullptr) {}
        explicit Node(T&& value) : item(std::move(value)), next(nullptr) {}
    };

    Node* head;
    Node* tail;
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
    Single_Linked_List() noexcept : head(nullptr), tail(nullptr), length(0) {}

    /**
     * @brief Copy constructor
     * @param other The list to copy from
     */
    Single_Linked_List(const Single_Linked_List& other) : head(nullptr), tail(nullptr), length(0) {
        Node* temp = other.head;
        while (temp != nullptr) {
            push_back(temp->item);
            temp = temp->next;
        }
    }

    /**
     * @brief Move constructor
     * @param other The list to move from
     */
    Single_Linked_List(Single_Linked_List&& other) noexcept 
        : head(other.head), tail(other.tail), length(other.length) {
        other.head = nullptr;
        other.tail = nullptr;
        other.length = 0;
    }

    /**
     * @brief Copy assignment operator
     * @param other The list to copy from
     * @return Reference to this list
     */
    Single_Linked_List& operator=(const Single_Linked_List& other) {
        if (this != &other) {
            clear();
            Node* temp = other.head;
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
    Single_Linked_List& operator=(Single_Linked_List&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            length = other.length;
            other.head = nullptr;
            other.tail = nullptr;
            other.length = 0;
        }
        return *this;
    }

    /**
     * @brief Destructor
     */
    ~Single_Linked_List() {
        clear();
    }

    /**
     * @brief Check if the list is empty
     * @return true if the list is empty, false otherwise
     */
    [[nodiscard]] bool empty() const noexcept {
        return length == 0;
    }

    /**
     * @brief Get the current length of the list
     * @return The number of elements in the list
     */
    [[nodiscard]] size_t size() const noexcept {
        return length;
    }

    /**
     * @brief Add an element to the end of the list
     * @param value The value to add
     */
    void push_back(const T& value) {
        Node* new_node = new Node(value);
        if (empty()) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
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
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        ++length;
    }

    /**
     * @brief Add an element to the front of the list
     * @param value The value to add
     */
    void push_front(const T& value) {
        Node* new_node = new Node(value);
        if (empty()) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
        ++length;
    }

    /**
     * @brief Add an element to the front of the list using move semantics
     * @param value The value to add
     */
    void push_front(T&& value) {
        Node* new_node = new Node(std::move(value));
        if (empty()) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
        ++length;
    }

    /**
     * @brief Insert an element at a specific position
     * @param index The position to insert at
     * @param value The value to insert
     * @throw std::out_of_range if index is out of range
     */
    void insert(size_t index, const T& value) {
        if (index > length) {
            throw std::out_of_range("Index out of range in insert()");
        }

        if (index == 0) {
            push_front(value);
        } else if (index == length) {
            push_back(value);
        } else {
            Node* new_node = new Node(value);
            Node* temp = head;
            for (size_t i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
            ++length;
        }
    }

    /**
     * @brief Remove the first element from the list
     * @throw std::runtime_error if the list is empty
     */
    void pop_front() {
        if (empty()) {
            throw std::runtime_error("List is empty in pop_front()");
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        --length;
    }

    /**
     * @brief Remove the last element from the list
     * @throw std::runtime_error if the list is empty
     */
    void pop_back() {
        if (empty()) {
            throw std::runtime_error("List is empty in pop_back()");
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        --length;
    }

    /**
     * @brief Remove an element at a specific position
     * @param index The position to remove from
     * @throw std::out_of_range if index is out of range
     */
    void erase(size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range in erase()");
        }

        if (index == 0) {
            pop_front();
        } else if (index == length - 1) {
            pop_back();
        } else {
            Node* temp = head;
            for (size_t i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            Node* to_delete = temp->next;
            temp->next = to_delete->next;
            delete to_delete;
            --length;
        }
    }

    /**
     * @brief Clear all elements from the list
     */
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    /**
     * @brief Reverse the list in-place
     */
    void reverse() {
        if (length <= 1) return;

        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        tail = head;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    /**
     * @brief Find the index of a value in the list
     * @param value The value to find
     * @return The index of the value, or -1 if not found
     */
    [[nodiscard]] size_t find(const T& value) const {
        Node* temp = head;
        size_t index = 0;
        while (temp != nullptr) {
            if (temp->item == value) return index;
            temp = temp->next;
            ++index;
        }
        return static_cast<size_t>(-1);
    }

    /**
     * @brief Print the list contents to standard output
     */
    void print() const {
        Node* temp = head;
        std::cout << "[ ";
        while (temp != nullptr) {
            std::cout << temp->item << ' ';
            temp = temp->next;
        }
        std::cout << ']' << std::endl;
    }

    /**
     * @brief Iterator class for the singly linked list
     */
    class Iterator {
    private:
        Node* current;

    public:
        using iterator_category = std::forward_iterator_tag;
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
        return Iterator(head);
    }

    /**
     * @brief Get an iterator to the end of the list
     * @return Iterator pointing past the last element
     */
    Iterator end() {
        return Iterator(nullptr);
    }
};

#endif // SINGLE_LINKED_LIST_H