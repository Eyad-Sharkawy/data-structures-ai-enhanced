# Data Structures Implementation (AI-Enhanced Version)

This is an enhanced version of the [Data Structures and Algorithms](https://github.com/Eyad-Sharkawy/Data-Structure-and-Algorithms) repository, featuring modern C++ features, comprehensive testing, and CI/CD support.

## Enhancements Over Original Version

- Added modern C++17 features (move semantics, STL-compatible iterators)
- Implemented comprehensive unit testing
- Added CI/CD pipeline with GitHub Actions
- Improved error handling with exceptions
- Enhanced documentation and code organization
- Added proper build system with CMake
- Implemented memory leak prevention
- Added cross-platform support

## Features

- Modern C++17 implementation
- Template-based design for type flexibility
- Move semantics support
- Exception handling and bounds checking
- Memory leak prevention
- Comprehensive error handling
- STL-compatible iterators
- Unit tests
- CI/CD with GitHub Actions
- Cross-platform support

## Implemented Data Structures

### 1. Doubly Linked List (`Doubly_Linked_List.h`)
A template-based implementation of a doubly linked list with bidirectional traversal capabilities:
- Dynamic memory management with proper destructors
- Template-based implementation for type flexibility
- Key operations:
  - Insertion: push_front, push_back, insert at index
  - Deletion: pop_front, pop_back, erase at index
  - List manipulation: reverse, clear
  - Smart traversal optimization (chooses shortest path to target node)
  - STL-compatible bidirectional iterators
  - Move semantics support

### 2. Single Linked List (`Linked_List.h`)
A template-based implementation of a singly linked list:
- Dynamic memory management
- Key operations:
  - Insertion: push_front, push_back, insert at index
  - Deletion: pop_front, pop_back, erase at index
  - List manipulation: reverse
  - Search functionality with find() method
  - Maintains both head and tail pointers
  - STL-compatible forward iterators
  - Move semantics support

### 3. Array-based Queue (`Array_Queue.h`)
A circular queue implementation using arrays:
- Fixed-size implementation with circular buffer
- Default size of 100 elements, customizable
- Key operations:
  - Enqueue and dequeue operations
  - Front and rear access
  - Full and empty state checking
  - Circular buffer implementation for efficient space usage
  - Exception handling for overflow/underflow

### 4. Linked List-based Queue (`Linked_Queue.h`)
A dynamic queue implementation using linked lists:
- Unlimited size (limited only by available memory)
- Key operations:
  - Enqueue and dequeue operations
  - Front and rear access
  - Queue clearing functionality
  - Dynamic memory management
  - Exception handling

### 5. Dynamic Array (`Linked_List_Array.h`)
A template-based dynamic array implementation:
- Fixed maximum size with dynamic content
- Key operations:
  - Insertion: push_front, push_back, insert at position
  - Deletion: erase at position
  - Element access and update
  - Array state management (empty, full)
  - Exception handling for bounds checking

## Building and Testing

### Prerequisites
- CMake 3.14 or higher
- C++17 compatible compiler
- Git

### Building
```bash
# Clone the repository
git clone https://github.com/yourusername/data-structures.git
cd data-structures

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
cmake --build .

# Run tests
ctest -C Debug --output-on-failure
```

### Running Tests
```bash
# Run all tests
./DataStructures_test

# Run specific test
./DataStructures_test --gtest_filter=DoublyLinkedListTest.*
```

## Usage Examples

### Doubly Linked List
```cpp
Doubly_Linked_List<int> list;
list.push_back(1);
list.push_front(0);
list.insert(1, 2);
list.print();  // Output: [ 0 2 1 ]

// Using iterators
for (const auto& item : list) {
    std::cout << item << ' ';
}

// Using move semantics
Doubly_Linked_List<int> list2 = std::move(list);
```

### Single Linked List
```cpp
Single_Linked_List<int> list;
list.push_back(1);
list.push_front(0);
list.insert(1, 2);
list.print();  // Output: [ 0 2 1 ]

// Using iterators
for (const auto& item : list) {
    std::cout << item << ' ';
}

// Using move semantics
Single_Linked_List<int> list2 = std::move(list);
```

### Array Queue
```cpp
Array_Queue<int> queue(10);  // Queue of size 10
queue.enqueue(1);
queue.enqueue(2);
queue.print();  // Output: [ 1 2 ]

try {
    queue.enqueue(3);
} catch (const std::overflow_error& e) {
    std::cerr << "Queue is full!" << std::endl;
}
```

### Linked Queue
```cpp
Linked_Queue<int> queue;
queue.enqueue(1);
queue.enqueue(2);
queue.print();  // Output: [ 1 2 ]

try {
    int front = queue.front();
    queue.dequeue();
} catch (const std::runtime_error& e) {
    std::cerr << "Queue is empty!" << std::endl;
}
```

### Dynamic Array
```cpp
Linked_List_Array<int> arr(10);  // Array of max size 10
arr.push_back(1);
arr.push_front(0);
arr.print();  // Output: [ 0 1 ]

try {
    arr.insert(1, 2);
} catch (const std::out_of_range& e) {
    std::cerr << "Index out of range!" << std::endl;
}
```

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Thanks to all contributors who have helped improve this project
- Inspired by the STL implementations
- Built with modern C++ best practices in mind