/**
    ECE250
    Deque.h
    - Purpose: Class defines the properties and valid operations of a deque data structures
    such as inserting, removing, clearing, printing, etc.
    - This class should create total abstraction of the idea of linked_list: hides the concept of nodes and low-level details

    Author: Yikai Zhou
    Version 1.0  - 27/01/2020
*/

#ifndef DEQUEDRIVER_DEQUE_H
#define DEQUEDRIVER_DEQUE_H
#include "DoublyLinkedList.h"

class Deque {
private:
    // member is a pointer to a linked list initialized in constructor
    DoublyLinkedList *my_deque;
public:
    // constructor and destructor
    Deque();
    ~Deque();
    // insertion methods
    void enqueue_front(int i);
    void enqueue_back(int i);
    // deletion methods
    void dequeue_front();
    void dequeue_back();
    // printing methods
    void print_forward();
    void print_backward();
    // empty list
    void clear();
    // accessors
    int get_front();
    int get_back();
    bool is_empty();
    int get_size();
};

#endif //DEQUEDRIVER_DEQUE_H