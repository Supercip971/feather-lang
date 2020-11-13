#include "cli.h"
#include <cwchar>
#include <stdio.h>
#include "feather/utility.h"
#include <iostream>
int run_cli(){

    printf("running feather CLI v%i.%i \n", feather::version, feather::subversion);
    char* command = new char[1000];
    while(true){
        printf(">");
        fgets(command, 1000,stdin);
    }
    
    return 0;
}