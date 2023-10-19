#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

void * alloc(std::size_t chunk_size){
    return nullptr;
}

void dealloc(void * chunk){
    
}

int main(int argc, char *argv[])
{
    //exit if there is not 2 args (call & datafile)
    if(argc != 2){
        std::cout << "Error: Invalid number of arguments!" << std::endl;
        std::cout << "Correct Usage: ./program <data file>" << std::endl;
        return EXIT_FAILURE;
    }

    // Test if given file is valid, exit if not
    std::ifstream datafile(argv[1]);
    if(!datafile){
        std::cout << "Error: Given file not valid or doesn't exist!" << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;

    while (getline (datafile, line)) {
        // Output the text from the file
        std::cout << line << std::endl;
    }

    return EXIT_SUCCESS;
}