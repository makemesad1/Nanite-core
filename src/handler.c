#ifdef __cplusplus
extern "C" {
#endif

typedef void (*clb_ptr)();

static clb_ptr clb_arr [228] __attribute__((section(".intclb"), used));

enum HANLDER_TYPE{
    NMI,
    HARDFAULT,
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




void register_irq_handler(int i, void (*func)(void)){
    clb_arr[i] = func;
}


void NMI_Handler(){
    clb_ptr clb = clb_arr[NMI];
    clb();
}


void HardFault_Handler(){
    clb_ptr clb = clb_arr[HARDFAULT];
    clb();
}

void MemManage_Handler(){
    clb_ptr clb = clb_arr[MEMMANGE];
    clb();
}

void BusFault_Handler(){

}

void UsageFault_Handler(){

}

void SVC_Handler(){

}

void DebugMon_Handler(){

}

void PendSV_Handler(){

}

void SysTick_Handler(){

}   

void WWDG_IRQHandler()
{

}   

void PVD_IRQHandler()
{

}   

void TAMP_STAMP_IRQHandler()
{

}   

void RTC_WKUP_IRQHandler()
{

}   

void FLASH_IRQHandler()
{

}   

void RCC_IRQHandler()
{

}   

void EXTI0_IRQHandler()
{

}   

void EXTI1_IRQHandler()
{

}   

void EXTI2_IRQHandler()
{

}   

void EXTI3_IRQHandler()
{

}   

void EXTI4_IRQHandler()
{

}   

void DMA1_Stream0_IRQHandler()
{

}   

void DMA1_Stream1_IRQHandler(){

}   

void DMA1_Stream2_IRQHandler(){

}   

void DMA1_Stream3_IRQHandler(){

}   

void DMA1_Stream4_IRQHandler(){

}   

void DMA1_Stream5_IRQHandler(){

}   

void DMA1_Stream6_IRQHandler(){

}   

void ADC_IRQHandler()    
{

}   

void CAN1_TX_IRQHandler() 
{

}   

void CAN1_RX0_IRQHandler() 
{

}   

void CAN1_RX1_IRQHandler() 
{

}   

void CAN1_SCE_IRQHandler() 
{

}   

void EXTI9_5_IRQHandler() 
{

}   

void TIM1_BRK_TIM9_IRQHandler()
{

}   

void TIM1_UP_TIM10_IRQHandler()
{

}   

void TIM1_TRG_COM_TIM11_IRQHandler()  
{

}

void TIM1_CC_IRQHandler()             
{

}

void TIM2_IRQHandler() 
{

}   

void TIM3_IRQHandler() 
{

}   

void TIM4_IRQHandler() 
{

}   

void I2C1_EV_IRQHandler()   
{

}   

void I2C1_ER_IRQHandler()  
{

}   

void I2C2_EV_IRQHandler()   
{

}   

void I2C2_ER_IRQHandler()  
{

}   

void SPI1_IRQHandler()    
{

}   

void SPI2_IRQHandler()    
{

}   

void USART1_IRQHandler()   
{

}   

void USART2_IRQHandler()     
{

}   

void USART3_IRQHandler()    
{

}   

void EXTI15_10_IRQHandler()    
{

}   

void RTC_Alarm_IRQHandler()    
{

}   

void OTG_FS_WKUP_IRQHandler()    
{

}   

void TIM8_BRK_TIM12_IRQHandler()  
{

}   

void TIM8_UP_TIM13_IRQHandler()    
{

}   

void TIM8_TRG_COM_TIM14_IRQHandler() 
{

} 

void TIM8_CC_IRQHandler()      
{

}   

void DMA1_Stream7_IRQHandler()  
{

}   

void FMC_IRQHandler()        
{

}   

void SDMMC1_IRQHandler()     
{

}   

void TIM5_IRQHandler() 
{

}   

void SPI3_IRQHandler()  
{

}   

void UART4_IRQHandler()  
{

}   

void UART5_IRQHandler()   
{

}   

void TIM6_DAC_IRQHandler() 
{

}   

void TIM7_IRQHandler()   
{

}   

void DMA2_Stream0_IRQHandler()  
{

}   

void DMA2_Stream1_IRQHandler() 
{

}   

void DMA2_Stream2_IRQHandler()  
{

}   

void DMA2_Stream3_IRQHandler()  
{

}   

void DMA2_Stream4_IRQHandler()  
{

}   

void ETH_IRQHandler()        
{

}   

void ETH_WKUP_IRQHandler()  
{

}   

void CAN2_TX_IRQHandler()   
{

}   

void CAN2_RX0_IRQHandler()  
{

}   

void CAN2_RX1_IRQHandler()  
{

}   

void CAN2_SCE_IRQHandler()  
{

}   

void OTG_FS_IRQHandler()  
{

}   

void DMA2_Stream5_IRQHandler()  
{

}   

void DMA2_Stream6_IRQHandler() 
{

}   

void DMA2_Stream7_IRQHandler() 
{

}   

void USART6_IRQHandler()    
{

}   

void I2C3_EV_IRQHandler() 
{

}   

void I2C3_ER_IRQHandler() 
{

}   

void OTG_HS_EP1_OUT_IRQHandler()  
{

}   

void OTG_HS_EP1_IN_IRQHandler()  
{

}   

void OTG_HS_WKUP_IRQHandler()  
{

}   

void OTG_HS_IRQHandler()    
{

}   

void DCMI_IRQHandler() 
{

}   

void RNG_IRQHandler()  
{

}   

void FPU_IRQHandler()  
{

}   

void UART7_IRQHandler()  
{

}   

void UART8_IRQHandler() 
{

}   

void SPI4_IRQHandler()  
{

}   

void SPI5_IRQHandler()  
{

}   

void SPI6_IRQHandler()   
{

}   

void SAI1_IRQHandler()  
{

}   

void LTDC_IRQHandler()  
{

}   

void LTDC_ER_IRQHandler() 
{

}   

void DMA2D_IRQHandler()  
{

}   

void SAI2_IRQHandler()   
{

}   

void QUADSPI_IRQHandler()
{

}   

void LPTIM1_IRQHandler()  
{

}   

void CEC_IRQHandler()    
{

}   

void I2C4_EV_IRQHandler() 
{

}   

void I2C4_ER_IRQHandler() 
{

}   

void SPDIF_RX_IRQHandler() 
{

}   


#ifdef __cplusplus
}
#endif