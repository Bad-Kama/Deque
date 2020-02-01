/**
    ECE250
    Node.h
    Purpose: Class defines the properties of nodes in a doubly linked-list that stores an int and points to a previous node and next node

    Author: Yikai Zhou
    Version 1.0  - 27/01/2020
*/

#include "Node.h"

/**
initializes data and node pointers: default constructor
*/
Node::Node(int data) : data{data}, next{nullptr}, previous{nullptr}{

}

/**
initializes data and node pointers: declaring a node with another node
*/
Node::Node(Node *node) : data{node -> data}, next{node -> next}, previous{node -> previous}{

}