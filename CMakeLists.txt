cmake_minimum_required(VERSION 3.15)
project(dequedriver)

set(CMAKE_CXX_STANDARD 11)

add_executable(dequedriver dequedriver.cpp DoublyLinkedList.cpp DoublyLinkedList.h Node.cpp Node.h Deque.cpp Deque.h)