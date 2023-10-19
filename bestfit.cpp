#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>



//
// BEST FIT!
//

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
        std::cout << "Correct Usage: ./program <Data File>" << std::endl;
        return EXIT_FAILURE;
    }

    // Test if given file is valid, exit if not
    std::ifstream datafile(argv[1]);
    if(!datafile){
        std::cout << "Error: Given file not valid or doesn't exist!" << std::endl;
        return EXIT_FAILURE;
    }

    //Read datafile, and perform given operations
    std::string line;
    while (getline (datafile, line)) {
        // Output the text from the file
        std::string delimiter = ": ";
        
        //Split string to check it its alloc or dealloc
        std::string command = line.substr(0, line.find(delimiter));

        //Allocation Command
        if(command == "alloc"){
            //Split allocation size from line
            std::string allocation_size = line.substr(line.find(delimiter) + int(delimiter.length()), line.length());

            //convert allocation size to integer
            int allocation_size_int = stoi(allocation_size);

            //DEBUG: print info REMOVE LATER
            std::cout << "Alloc Called, Allocation size: " << allocation_size_int << std::endl;

            //Call Allocation function
            //COMLETE!!!!!!!!
        }

        //Deallocation Command
        else if(command == "dealloc"){
            //DEBUG: print info REMOVE LATER
            std::cout << "Dealloc Called" << std::endl;
            
            //Call Deallocation function
            //COMLETE!!!!!!!!
        }

        //Invalid Command
        else{
            std::cout << "Invalid Command in datafile. Quitting!" << std::endl;
            return EXIT_FAILURE;
        }
    }

    datafile.close();

    //PRINT EXIT DATA HERE

    return EXIT_SUCCESS;
}