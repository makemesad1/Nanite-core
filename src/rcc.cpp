#pragma once

#include "rcc.h"

__RCC::__RCC(){
    //Initialize all pointers
    CR = (uint32_t *) 0x0;
}

void __RCC::MCO1_Enable(int source, int division){
    
}