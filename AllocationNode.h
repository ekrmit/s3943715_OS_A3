#ifndef ALLOCATION_NODE_H
#define ALLOCATION_NODE_H

#include <cstddef>

struct AllocationNode{
    //Allocated Block Size
    std::size_t block_size;

    //Used amount of allocated block size
    std::size_t used_size;

    //Memory address ptr
    void *space;

    //For when list needs to find matching node 
    // in method <list name>.remove()
    bool operator==(const AllocationNode& rhs) const {
        return (rhs.space == space);
    }
};

#endif //ALLOCATION_NODE_H