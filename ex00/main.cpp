#include "Converter.hpp"
#include <iostream>

int main (int argc, char **argv){

    if(argc != 2){
        std::cout << "Bad argument" << std::endl;
        return(0);
    }

    Converter convertisseur(argv[1]);

    return (0);
}
