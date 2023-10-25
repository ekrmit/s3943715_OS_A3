#ifndef FIRST_FIT_H
#define FIRST_FIT_H

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <list>

#include "AllocationNode.h"

class FirstFit{
    public:
        FirstFit();
        void *alloc(std::size_t chunk_size);
        bool dealloc(void * chunk);
        size_t get_allocation_size(int job_size);
        void* get_last_allocated();

        //get totals for data comparison
        int get_total_allocated();
        int get_total_used();
        int get_total_free();

        //print the lists in a table
        void print_allocated();
        void print_free();

    private:
        std::list<AllocationNode> occupied_chunks;
        std::list<AllocationNode> free_chunks;

};

#endif //FIRST_FIT_H