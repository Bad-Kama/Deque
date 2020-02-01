/**
    ECE250
    DoublyLinkedList.cpp
    - Purpose: Class defines the properties and the full set of valid operations of a doubly linked-list data strucures
    with valid operations such as insertion, deletion, printing, etc.

    Author: Yikai Zhou
    Version 1.0  - 27/01/2020
*/

#include "DoublyLinkedList.h"

/**
initializes pointer and list size
*/
DoublyLinkedList::DoublyLinkedList() {
    tail = nullptr;
    head = nullptr;
    list_size = 0;
}

/**
deallocates every node by calling the deletion method
*/
DoublyLinkedList::~DoublyLinkedList() {
    while(list_size != 0) {
        remove(0);
    }
}

/**
prints list from head to tail
*/
void DoublyLinkedList::print_forward(){

    if(list_size != 0) {
        Node *current = head;
        while (current != nullptr) {
            std::cout <<  current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

/**
 * handles 4 cases: list is empty, insert front, insert back, insert middle
 * error occurs when index > size
 * index 0 means insert at position 0 -> insert at head
 * index 10 in a list of size 10 means insert at tail (size = index)
*/
void DoublyLinkedList::insert(int index, int data) {

    //

    try {
        if(index > list_size) {
            throw std::out_of_range("Given index is out of range");
        }
        Node *new_node = new Node{data};
        if(list_size == 0) { //list empty: checked

            new_node -> next = nullptr;
            new_node -> previous = nullptr;
            head = new_node;
            tail = new_node;

        } else if(index == 0) { //insert first: checked

            new_node -> next = head;
            new_node -> previous = nullptr;
            head -> previous = new_node;
            head = new_node;

        } else if(index == list_size) { //insert last: checked

            new_node -> next = nullptr;
            new_node -> previous = tail;
            tail -> next = new_node;
            tail = new_node;

        } else { //insert at index: checked

            Node *current = head;
            for(int i = 0; i < index; ++ i) {
                current = current -> next;
            }
            new_node -> next = current;
            new_node -> previous = current -> previous;

            current -> previous = new_node;
            new_node -> previous -> next = new_node;
        }
        ++list_size;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    } //
}

/**
returns the size of list
*/
int DoublyLinkedList::get_size() {
    return list_size;
}

/**
prints list from tail to head
*/
void DoublyLinkedList::print_backward() {
    if(list_size != 0) {
        Node *current = tail;
        //int counter = 0;
        while (current != nullptr) {
            std::cout <<  current->data << " ";
            current = current->previous;
            //++counter;
        }
        std::cout << std::endl;
    }
}

/**
 * handles 5 cases: list is empty, list has one node, remove front, remove back, remove middle
 * error occurs when list empty
 * index 0 means remove tail at position 0 -> insert at head
 * index 10 in a list of size 10 means remove tail
*/
void DoublyLinkedList::remove(int index) {
    try {
        if(list_size == 0) {
            throw std::invalid_argument("Cannot remove from an empty list");
        } else if(index > list_size - 1) {
            throw std::out_of_range("Index out of range");
        }
        Node* current;
        if (list_size == 1) {

            current = head;
            head = nullptr;
            tail = nullptr;

        } else if(index == 0) {

            current = head;
            head = current -> next;
            head -> previous = nullptr;

        } else if(index == list_size - 1) {

            current = tail;
            tail = current -> previous;
            tail -> next = nullptr;

        } else {

            current = head;
            for(int i = 0; i < index; ++i) {
                current = current -> next;
            }

            current -> previous -> next = current -> next; // previous node's next = current node's next
            current -> next -> previous = current -> previous; // next node's previous = current node's previous

            /* Node* previous_node = current -> previous;  /// Alternative code
             Node* next_node = current -> next;
             previous_node -> next = next_node;
             next_node -> previous = previous_node; */
        }
        -- list_size;
        delete current; // deallocates memory

    } catch (std::exception& e) {
        std::cout << e.what() << std::endl; // prints empty_list_exception
        return;
    }
}

/**
returns data stored in head
*/
int DoublyLinkedList::get_data_head() {
    return head -> data;
}

/**
returns data stored in tail
*/
int DoublyLinkedList::get_data_tail() {
    return tail -> data;
}