#include <cassert>
#include <iostream>
#include <string>
#include "Doubly_Linked_List.h"
#include "Linked_List.h"
#include "Array_Queue.h"
#include "Linked_Queue.h"
#include "Linked_Stack.h"
#include "Array_Stack.h"
#include "Linked_List_Array.h"

// Helper function to print test results
void print_test_result(const std::string& test_name, bool passed) {
    std::cout << test_name << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Test Doubly Linked List
void test_doubly_linked_list() {
    std::cout << "\nTesting Doubly Linked List:" << std::endl;
    
    Doubly_Linked_List<int> list;
    bool passed = true;

    // Test empty list
    passed &= list.empty();
    passed &= list.size() == 0;
    print_test_result("Empty list", passed);

    // Test push_back
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    passed = list.size() == 3;
    print_test_result("Push back", passed);

    // Test push_front
    list.push_front(0);
    passed = list.size() == 4;
    print_test_result("Push front", passed);

    // Test insert
    list.insert(2, 5);
    passed = list.size() == 5;
    print_test_result("Insert", passed);

    // Test pop_front
    list.pop_front();
    passed = list.size() == 4;
    print_test_result("Pop front", passed);

    // Test pop_back
    list.pop_back();
    passed = list.size() == 3;
    print_test_result("Pop back", passed);

    // Test erase
    list.erase(1);
    passed = list.size() == 2;
    print_test_result("Erase", passed);

    // Test reverse
    list.reverse();
    passed = list.size() == 2;
    print_test_result("Reverse", passed);

    // Test move semantics
    Doubly_Linked_List<int> list2 = std::move(list);
    passed = list2.size() == 2 && list.empty();
    print_test_result("Move semantics", passed);
}

// Test Single Linked List
void test_single_linked_list() {
    std::cout << "\nTesting Single Linked List:" << std::endl;
    
    Single_Linked_List<int> list;
    bool passed = true;

    // Test empty list
    passed &= list.empty();
    passed &= list.size() == 0;
    print_test_result("Empty list", passed);

    // Test push_back
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    passed = list.size() == 3;
    print_test_result("Push back", passed);

    // Test push_front
    list.push_front(0);
    passed = list.size() == 4;
    print_test_result("Push front", passed);

    // Test insert
    list.insert(2, 5);
    passed = list.size() == 5;
    print_test_result("Insert", passed);

    // Test pop_front
    list.pop_front();
    passed = list.size() == 4;
    print_test_result("Pop front", passed);

    // Test pop_back
    list.pop_back();
    passed = list.size() == 3;
    print_test_result("Pop back", passed);

    // Test erase
    list.erase(1);
    passed = list.size() == 2;
    print_test_result("Erase", passed);

    // Test reverse
    list.reverse();
    passed = list.size() == 2;
    print_test_result("Reverse", passed);

    // Test find
    size_t index = list.find(2);
    passed = index != static_cast<size_t>(-1);
    print_test_result("Find", passed);

    // Test move semantics
    Single_Linked_List<int> list2 = std::move(list);
    passed = list2.size() == 2 && list.empty();
    print_test_result("Move semantics", passed);
}

// Test Array Queue
void test_array_queue() {
    std::cout << "\nTesting Array Queue:" << std::endl;
    
    Array_Queue<int> queue(5);
    bool passed = true;

    // Test empty queue
    passed &= queue.empty();
    print_test_result("Empty queue", passed);

    // Test enqueue
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    passed = !queue.empty();
    print_test_result("Enqueue", passed);

    // Test dequeue
    int value = queue.dequeue();
    passed = value == 1;
    print_test_result("Dequeue", passed);

    // Test front
    value = queue.front();
    passed = value == 2;
    print_test_result("Front", passed);

    // Test full queue
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    passed = queue.full();
    print_test_result("Full queue", passed);
}

// Test Linked Queue
void test_linked_queue() {
    std::cout << "\nTesting Linked Queue:" << std::endl;
    
    Linked_Queue<int> queue;
    bool passed = true;

    // Test empty queue
    passed &= queue.empty();
    print_test_result("Empty queue", passed);

    // Test enqueue
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    passed = !queue.empty();
    print_test_result("Enqueue", passed);

    // Test dequeue
    int value = queue.dequeue();
    passed = value == 1;
    print_test_result("Dequeue", passed);

    // Test front
    value = queue.front();
    passed = value == 2;
    print_test_result("Front", passed);

    // Test clear
    queue.clear();
    passed = queue.empty();
    print_test_result("Clear", passed);
}

// Test Linked Stack
void test_linked_stack() {
    std::cout << "\nTesting Linked Stack:" << std::endl;
    
    Linked_Stack<int> stack;
    bool passed = true;

    // Test empty stack
    passed &= stack.empty();
    print_test_result("Empty stack", passed);

    // Test push
    stack.push(1);
    stack.push(2);
    stack.push(3);
    passed = !stack.empty();
    print_test_result("Push", passed);

    // Test pop
    int value = stack.pop();
    passed = value == 3;
    print_test_result("Pop", passed);

    // Test top
    value = stack.top();
    passed = value == 2;
    print_test_result("Top", passed);

    // Test clear
    stack.clear();
    passed = stack.empty();
    print_test_result("Clear", passed);
}

// Test Array Stack
void test_array_stack() {
    std::cout << "\nTesting Array Stack:" << std::endl;
    
    Array_Stack<int> stack(5);
    bool passed = true;

    // Test empty stack
    passed &= stack.empty();
    print_test_result("Empty stack", passed);

    // Test push
    stack.push(1);
    stack.push(2);
    stack.push(3);
    passed = !stack.empty();
    print_test_result("Push", passed);

    // Test pop
    int value = stack.pop();
    passed = value == 3;
    print_test_result("Pop", passed);

    // Test top
    value = stack.top();
    passed = value == 2;
    print_test_result("Top", passed);

    // Test full stack
    stack.push(4);
    stack.push(5);
    stack.push(6);
    passed = stack.full();
    print_test_result("Full stack", passed);
}

// Test Linked List Array
void test_linked_list_array() {
    std::cout << "\nTesting Linked List Array:" << std::endl;
    
    Linked_List_Array<int> array(5);
    bool passed = true;

    // Test empty array
    passed &= array.empty();
    print_test_result("Empty array", passed);

    // Test push_back
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    passed = !array.empty();
    print_test_result("Push back", passed);

    // Test push_front
    array.push_front(0);
    passed = array.size() == 4;
    print_test_result("Push front", passed);

    // Test insert
    array.insert(2, 5);
    passed = array.size() == 5;
    print_test_result("Insert", passed);

    // Test erase
    array.erase(1);
    passed = array.size() == 4;
    print_test_result("Erase", passed);

    // Test full array
    array.push_back(6);
    passed = array.full();
    print_test_result("Full array", passed);
}

int main() {
    std::cout << "Starting Data Structures Tests..." << std::endl;

    test_doubly_linked_list();
    test_single_linked_list();
    test_array_queue();
    test_linked_queue();
    test_linked_stack();
    test_array_stack();
    test_linked_list_array();

    std::cout << "\nAll tests completed!" << std::endl;
    return 0;
}
