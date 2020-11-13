#include "interpreter.h"
#include "utility.h"



namespace feather {
    void interpreter::start(char* buffer){

        context.log("starting interpreter ... \n");
        context.log(buffer);
        context.current_line = 0;
        context.current_add = 0;
        
    }
}