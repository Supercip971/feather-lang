#pragma once
#include <iostream>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h> 
#include <fstream>
#include <cstring>



namespace feather
{

    constexpr unsigned int version = 0;
    constexpr unsigned int subversion = 1;
    class gcontext
    {

    public:
        unsigned int current_line;
        unsigned int current_add = 1;
        bool error = false;
        const char *last_error;
        void generate_error(const char *error_name, ...)
        {
            va_list vl;
            va_start(vl,error_name);
            error = true;

            char* target = new char[strlen(error_name) + 20];
            vsprintf(target, error_name, vl);
            fprintf(stderr, "\033[1;31m[ ERROR ]\033[0m %s at line %i at %i \n", target, current_line, current_add);
            va_end(vl);
            delete [] target;
        }

        void log(const char* message, ...){

            va_list vl;
            va_start(vl,message);


            error = true;

            char* target = new char[strlen(message) + 20];
            vsprintf(target, message, vl);
            FILE* f = fopen("output", "w");
            fprintf(f, "\033[1;36m[ %i / %i ]\033[0m %s  \n", current_line, current_add, target);
            va_end(vl);
            delete [] target;

            fclose(f);

        }
    };

    static gcontext context;
} // namespace feather