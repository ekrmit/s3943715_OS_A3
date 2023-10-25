#include "FirstFit.h"

FirstFit::FirstFit(){};

void* FirstFit::alloc(std::size_t chunk_size){
    // //create a return variable to store answer
    void* return_ptr;

    //bool to stop double allocation
    bool allocated = false;

    // //If there are free chunks search for a suitable one.
    if(!free_chunks.empty()){
        for(AllocationNode alloc : free_chunks){
            if(alloc.block_size >= chunk_size){
                //remove from free chunks
                free_chunks.remove(alloc);

                //set used amount to chunk_size & add to occupuied_chunks
                alloc.used_size = chunk_size;
                occupied_chunks.push_back(alloc);

                //set return ptr and bool
                return_ptr = alloc.space;
                allocated = true;
                break;
            }
        }
    }

    //Request heap growth if none/no-valid free chunks
    if(!allocated){
        //create a new allocation
        AllocationNode alloc;
        alloc.block_size = get_allocation_size(chunk_size);
        alloc.used_size = chunk_size;
        alloc.space = sbrk(alloc.block_size);

        //add new allocation to allocated list
        occupied_chunks.push_back(alloc);
        return_ptr = alloc.space;
    }

    return return_ptr;
};

bool FirstFit::dealloc(void * chunk){
    bool success = false;

    for(AllocationNode alloc : occupied_chunks){
        if(alloc.space == chunk){
            //remove from allocated list
            occupied_chunks.remove(alloc);

            //clear data and add to free list
            alloc.used_size = 0;
            free_chunks.push_back(alloc);
            success = true;
            break;
        }
    }

    return success;
}

size_t FirstFit::get_allocation_size(int job_size){
    int valid_partition_sizes[] = {32, 64, 128, 256, 512};
    size_t return_value; 
    for(int i = 0; i < 5; i++){
        if(valid_partition_sizes[i] >= job_size){
            return_value = valid_partition_sizes[i];
            break;
        }
    }
    return return_value;
};

void* FirstFit::get_last_allocated(){
    //If Dealloc Called on Empty Chunks List,
    //call fatal error
    if(occupied_chunks.empty()){
        return nullptr;
    }

    AllocationNode alloc = occupied_chunks.back();
    return alloc.space;
}

int FirstFit::get_total_allocated(){
    int total = 0;
    for(AllocationNode alloc : occupied_chunks){
        total += alloc.block_size;
    }
    return total;
}

int FirstFit::get_total_used(){
    int total = 0;
    for(AllocationNode alloc : occupied_chunks){
        total += alloc.used_size;
    }
    return total;
}

int FirstFit::get_total_free(){
    int total = 0;
    for(AllocationNode alloc : free_chunks){
        total += alloc.block_size;
    }
    return total;
}

void FirstFit::print_allocated(){
    std::cout << std::endl;

    //Table Title and Headers
    std::cout << "\033[1;4;33m" << "Allocated Chunks List:" << "\033[0m" << std::endl;
    std::cout << std::setw(15) << "Address" 
              << std::setw(15) << "Total Size" 
              << std::setw(15) << "Total Used" << std::endl;
    std::cout << std::setw(15) << "---------------" 
              << std::setw(15) << "---------------" 
              << std::setw(15) << "---------------" << std::endl;

    //print each list item as a table row
    for(AllocationNode alloc : occupied_chunks){
        std::cout << std::setw(15) << alloc.space 
                  << std::setw(15) << alloc.block_size 
                  << std::setw(15) << alloc.used_size << std::endl;
    }

    //PRINT TOTALS
    std::cout << "        " << std::setw(15) << "\033[1;34mTOTALS:\033[0m"
              << std::setw(15) << get_total_allocated()
              << std::setw(15) << get_total_used() << std::endl;
}

void FirstFit::print_free(){
    std::cout << std::endl;

    //Table Title and Headers
    std::cout << "\033[1;4;33m" << "Free Chunks List:" << "\033[0m" << std::endl;
    std::cout << std::setw(15) << "Address" 
              << std::setw(15) << "Total Size" << std::endl;
    std::cout << std::setw(15) << "---------------" 
              << std::setw(15) << "---------------" << std::endl;

    //print each list item as a table row
    for(AllocationNode alloc : free_chunks){
        std::cout << std::setw(15) << alloc.space 
                  << std::setw(15) << alloc.block_size << std::endl;
    }

    //PRINT TOTALS
    std::cout << "         " << std::setw(15) << "\033[1;34mTOTAL:\033[0m"
              << std::setw(15) << get_total_free() << std::endl;
}