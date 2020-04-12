#pragma once

#include "types.h"

class __RCC{
    public:

    //constructor
    __RCC();

    //Register map
    volatile uint32_t const *CR;
    volatile uint32_t const *PLLCFGR;
    volatile uint32_t const *CFGR;
    volatile uint32_t const *AHB1ENR;

    //Functionality
    void MCO1_Enable(int source, int division);

};

