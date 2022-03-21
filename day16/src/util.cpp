#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void errif(bool condition, const char *errmsg){
    if(condition){
        std::cout << errmsg << std::endl;
        exit(EXIT_FAILURE);
    }
}