#ifndef ALLOCATION_NODE_H
#define ALLOCATION_NODE_H

#include <cstddef>

struct AllocationNode{
    std::size_t size;
    void *space;
};

#endif //ALLOCATION_NODE_H