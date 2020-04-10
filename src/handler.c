#ifdef __cplusplus
extern "C" {
#endif


enum HANLDER_TYPE{
    MEMMANGE,
    BUSFAULT,
    USAGEFAULT,
    SVCALL,
    DEBUGMON,
    PENDSV,
    SYSTICK,
    WWDG,
    PVD,
    TAMPSTAMP,
    RTCWAKEUP,
    FLASH,
    RCC,
    EXTI0,
    EXTI1,
    EXTI2,
    EXTI3,
    EXTI4,
    DMASTREAM0,
    DMASTREAM1,
    DMASTREAM2,
    DMASTREAM3,
    DMASTREAM4,
    DMASTREAM5,
    DMSSTREAM6,
    ADC,
    CAN1_TX,
    CAN1_RX0,
    CAN1_RX1,
    CAN1_SCE,
    EXTI95,
    TIM1_BRK_TIM9,
    TIM1_UP_TIM10

    //Complete this list
};

int z = 6;
int q = 7;

void *clb_arr[228] __attribute__((section(".intclb"), used));

void register_handler(enum HANLDER_TYPE handler, void (*func)(void)){
    //Now register this handler in ram i guess
}

#ifdef __cplusplus
}
#endif