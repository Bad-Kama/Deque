/**
    ECE250
    Deque.cpp
    - Purpose: Class defines the properties and valid operations of a deque data structures
    such as inserting, removing, clearing, printing, etc.
    - This class should create total abstraction of the idea of linked_list: hides the concept of nodes and low-level details

    Author: Yikai Zhou
    Version 1.0  - 27/01/2020
*/

#include "Deque.h"

Deque::Deque() {
    my_deque = new DoublyLinkedList(); // allocates memory for linked_list
}

Deque::~Deque() {
    delete my_deque; // deallocates the dynamic data (linked_list) it has
}

void Deque::enqueue_front(int i) {
    my_deque -> insert(0, i); // insert at head node
}

void Deque::enqueue_back(int i) {
    my_deque -> insert(get_size(), i); // insert at tail node
}

void Deque::dequeue_front() {
    my_deque -> remove(0);  // removes head node
}

void Deque::dequeue_back() {
    my_deque -> remove(get_size()-1); // removes tail node
}

void Deque::clear() {
    delete my_deque;
    my_deque = new DoublyLinkedList; // sets the pointer to another dynamically allocated linked_list
}

int Deque::get_front() {
    return my_deque -> get_data_head(); // gets the data stored in the head node of the deque
}

int Deque::get_back() {
    return my_deque -> get_data_tail(); // gets the data stored in the tail node of the deque
}

bool Deque::is_empty() {
    return get_size() == 0; // returns true if deque is empty
}

int Deque::get_size() {
    return my_deque -> get_size(); // returns the size of deque
}

void Deque::print_forward() {
    my_deque->print_forward(); // prints deque from head to tail
}

void Deque::print_backward() {
    my_deque->print_backward(); // prints deque from tail to head
}

