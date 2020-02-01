/**
    ECE250
    Node.h
    Purpose: Class defines the properties of nodes in a doubly linked-list that stores an int and points to a previous node and next node

    Author: Yikai Zhou
    Version 1.0  - 27/01/2020
*/

#ifndef DEQUEDRIVER_NODE_H
#define DEQUEDRIVER_NODE_H


class Node {
public:
    // constructors
    Node(int data);
    Node(Node *node);
    // data
    int data;
    // node pointers
    Node *next;
    Node *previous;
};

#endif //DEQUEDRIVER_NODE_H