cmake_minimum_required(VERSION 3.30)
project(Data_Structure)

set(CMAKE_CXX_STANDARD 20)

add_executable(Data_Structure main.cpp
        Array_Stack.h
        Array_Queue.h
        Linked_Stack.h
        Linked_Queue.h
        Linked_List_Array.h
        Linked_Queue.h
        Doubly_Linked_List.h)
