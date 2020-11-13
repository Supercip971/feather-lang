#include "feather/utility.h"
#include <fstream>

#include <iostream>
#include "feather/interpreter.h"
#include <filesystem>
#include <new>
#include <stdio.h>
#include "cli.h"

int main(int argc, char* argv[])
{

    if(argc == 1){
        return run_cli();
    }
    for(int i = 1; i < argc; i++){

        

        std::ifstream file_to_read;
        file_to_read.open(argv[i], std::ios::binary  | std::ios::ate);
        if(!file_to_read.is_open()){

            feather::context.generate_error("can't open file %s", argv[i]);
            return -1;
        }

        feather::interpreter nterpreter;
        std::streamsize size = file_to_read.tellg();
        file_to_read.seekg(0, std::ios::beg);

        char* buf = (char*)malloc(size+2);
        
        feather::context.log("opening file %s of length %i \n", argv[i], size);
        file_to_read.read(buf, size);
        buf[size+1] = 0;
        nterpreter.start(buf);

        free(buf);
        
    }

    return 0;
}
