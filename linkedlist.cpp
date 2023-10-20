#include "linkedlist.h"

linked_list::linked_list(){
    head = nullptr;
    tail = nullptr;
}

linked_list::~linked_list(){

}

void linked_list::append(size_t size, void *space){
    //Append for first item in list
    if(head == nullptr & tail == nullptr){
        //create new node
        std::shared_ptr<AllocationNode> newNode = std::make_shared<AllocationNode>();

        //set new node value to given chunk
        newNode->size = size;
        newNode->next = nullptr;
        head = newNode;
        tail = newNode;
    }
    else{
        std::shared_ptr<AllocationNode> newNode = std::make_shared<AllocationNode>();
        newNode->size = size;
        newNode->next = nullptr;

        //Append new item to end of list :)
        tail->next = newNode;
        tail = newNode;
    }
}

void linked_list::remove_last(){
    //if list empty, do nothing and return.
    if(head == nullptr & tail == nullptr){
        return;
    }

    //if only one element in list, deallocate head and return.
    if(head->next == nullptr){
        head = nullptr;
        tail = nullptr;
        return;
    }
    
    //delete last element in linked list (FILO DEALLOCATION)
    std::shared_ptr<AllocationNode> currNode = head;
    while(head->next != nullptr){
        //if the next node, is the last node, delete next, and set curr to last.
        if(currNode->next->next == nullptr){
            currNode->next = nullptr;
            tail = currNode;
            return;
        }
        currNode = currNode->next;
    }

}

void linked_list::print_list(){
    std::shared_ptr<AllocationNode> currNode = head;
    while(currNode != nullptr){
        std::cout << "Chunk used space: " << currNode->size << std::endl;
        currNode = currNode->next;
    }

}