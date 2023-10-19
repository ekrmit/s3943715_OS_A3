#ifndef ALLOCATION_H
#define ALLOCATION_H

#include <cstddef>

struct allocation
{
    std::size_t size;
    void *space;
};

#endif