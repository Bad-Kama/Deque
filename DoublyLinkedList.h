/**
    ECE250
    DoublyLinkedList.h
    - Purpose: Class defines the properties and the full set of valid operations of a doubly linked-list data strucures
    with valid operations such as insertion, deletion, printing, etc.

    Author: Yikai Zhou
    Version 1.0  - 27/01/2020
*/

#ifndef DEQUEDRIVER_DOUBLYLINKEDLIST_H
#define DEQUEDRIVER_DOUBLYLINKEDLIST_H
#include "Node.h"
#include <iostream>

class DoublyLinkedList {
private:
    // members: head node, tail node, size of list
    Node *head;
    Node* tail;
    int list_size;
public:
    // constructor and destructor
    DoublyLinkedList();
    ~DoublyLinkedList();

    // insertion, deletion, and printing
    void insert(int index, int data);
    void remove(int index);
    void print_forward();
    void print_backward();

    // accessors
    int get_size();
    int get_data_head();
    int get_data_tail();
};

#endif //DEQUEDRIVER_DOUBLYLINKEDLIST_H