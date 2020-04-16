#pragma once

#include "types.h"

#ifdef __cplusplus
namespace Nanite {
#endif

struct __RCC{

    uint32_t CR;
    uint32_t PLL_CFGR;
    uint32_t CFGR;
    uint32_t AHB1RSTR;
    uint32_t AHB2RSTR;
    uint32_t AHB3RSTR;
    uint32_t EMPT1;
    uint32_t APB1RSTR;
    uint32_t APB2RSTR;
    uint32_t EMTP2_3[2];
    uint32_t AHB1ENR;
    uint32_t AHB2ENR;
    uint32_t AHB3ENR;
    uint32_t EMPT4;
    uint32_t APB1ENR;
    uint32_t APB2ENR;
    uint32_t EMPT5_6[2];
    uint32_t AHB1LPENR;
    uint32_t AHB2LPENR;
    uint32_t AHB3LPENR;
    uint32_t EMPT7;
    uint32_t ABP1LPENR;
    uint32_t APB2LPENR;
    uint32_t EMPT8_9[2];
    uint32_t BDCR;
    uint32_t CSR;
    uint32_t EMPT10_11[2];
    uint32_t SSCGR;
    uint32_t PLLI2SCFGR;
    uint32_t PLLSAICFGR;
    uint32_t DCKCFGR1;
    uint32_t DCKCFGR2;

    //C++ Methods
    #ifdef __cplusplus

    __RCC(int regaddr); //constructor

    //C struct with function pointers
    #else

    void (*Construct)(int);

    #endif

};




#ifdef __cplusplus
}
#endif