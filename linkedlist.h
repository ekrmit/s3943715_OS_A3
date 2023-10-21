#ifndef LINKED_H
#define LINKED_H

#include <memory>
#include <cstddef>
#include <iostream>

struct AllocationNode{
    std::size_t size;
    void *space;
};

class linked_list {
public:
    linked_list();
    ~linked_list();

    // Function to add a node to the linked list
    void append(size_t size, void *space);

    // Function to remove a node from the linked list
    void remove_last(); //ADD ARG LATER!!!!!

    //method to print list
    void print_list();

private:
    std::shared_ptr<AllocationNode> head;
    std::shared_ptr<AllocationNode> tail;
};    

#endif