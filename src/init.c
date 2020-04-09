/* External symbols, loaded from linker script */
#ifdef __cplusplus
extern "C" {
#endif

extern void *_estack, *_sidata, *_sdata, *_edata, *_sbss, *_ebss;


/* External functions */


/* Initializes Data section and bss */ 	

void __attribute__((naked, noreturn)) Reset_Handler()
{

	void **pSource, **pDest;
	for (pSource = &_sidata, pDest = &_sdata; pDest != &_edata; pSource++, pDest++)
		*pDest = *pSource;

	for (pDest = &_sbss; pDest != &_ebss; pDest++)
		*pDest = 0;
		
	while(1);

}

/* Default Handler for all interupts */

void __attribute__((naked, noreturn)) Default_Handler(){

	for(;;);

}

/* Weak Aliases for all interupt handlers, defaulting to Default Handler */

void NMI_Handler()                    __attribute__ ((weak, alias ("Default_Handler")));
void HardFault_Handler()              __attribute__ ((weak, alias ("Default_Handler")));
void MemManage_Handler()              __attribute__ ((weak, alias ("Default_Handler")));
void BusFault_Handler()               __attribute__ ((weak, alias ("Default_Handler")));
void UsageFault_Handler()             __attribute__ ((weak, alias ("Default_Handler")));
void SVC_Handler()                    __attribute__ ((weak, alias ("Default_Handler")));
void DebugMon_Handler()               __attribute__ ((weak, alias ("Default_Handler")));
void PendSV_Handler()                 __attribute__ ((weak, alias ("Default_Handler")));
void SysTick_Handler()                __attribute__ ((weak, alias ("Default_Handler")));
void WWDG_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void PVD_IRQHandler()                 __attribute__ ((weak, alias ("Default_Handler")));
void TAMP_STAMP_IRQHandler()          __attribute__ ((weak, alias ("Default_Handler")));
void RTC_WKUP_IRQHandler()            __attribute__ ((weak, alias ("Default_Handler")));
void FLASH_IRQHandler()               __attribute__ ((weak, alias ("Default_Handler")));
void RCC_IRQHandler()                 __attribute__ ((weak, alias ("Default_Handler")));
void EXTI0_IRQHandler()               __attribute__ ((weak, alias ("Default_Handler")));
void EXTI1_IRQHandler()               __attribute__ ((weak, alias ("Default_Handler")));
void EXTI2_IRQHandler()               __attribute__ ((weak, alias ("Default_Handler")));
void EXTI3_IRQHandler()               __attribute__ ((weak, alias ("Default_Handler")));
void EXTI4_IRQHandler()               __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream0_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream1_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream2_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream3_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream4_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream5_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream6_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void ADC_IRQHandler()                 __attribute__ ((weak, alias ("Default_Handler")));
void CAN1_TX_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void CAN1_RX0_IRQHandler()            __attribute__ ((weak, alias ("Default_Handler")));
void CAN1_RX1_IRQHandler()            __attribute__ ((weak, alias ("Default_Handler")));
void CAN1_SCE_IRQHandler()            __attribute__ ((weak, alias ("Default_Handler")));
void EXTI9_5_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler()       __attribute__ ((weak, alias ("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler()       __attribute__ ((weak, alias ("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler()  __attribute__ ((weak, alias ("Default_Handler")));
void TIM1_CC_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void TIM2_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void TIM3_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void TIM4_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void I2C1_EV_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void I2C1_ER_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void I2C2_EV_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void I2C2_ER_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void SPI1_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void SPI2_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void USART1_IRQHandler()              __attribute__ ((weak, alias ("Default_Handler")));
void USART2_IRQHandler()              __attribute__ ((weak, alias ("Default_Handler")));
void USART3_IRQHandler()              __attribute__ ((weak, alias ("Default_Handler")));
void EXTI15_10_IRQHandler()           __attribute__ ((weak, alias ("Default_Handler")));
void RTC_Alarm_IRQHandler()           __attribute__ ((weak, alias ("Default_Handler")));
void OTG_FS_WKUP_IRQHandler()         __attribute__ ((weak, alias ("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler()      __attribute__ ((weak, alias ("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler()       __attribute__ ((weak, alias ("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler()  __attribute__ ((weak, alias ("Default_Handler")));
void TIM8_CC_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream7_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void FMC_IRQHandler()                 __attribute__ ((weak, alias ("Default_Handler")));
void SDMMC1_IRQHandler()              __attribute__ ((weak, alias ("Default_Handler")));
void TIM5_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void SPI3_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void UART4_IRQHandler()               __attribute__ ((weak, alias ("Default_Handler")));
void UART5_IRQHandler()               __attribute__ ((weak, alias ("Default_Handler")));
void TIM6_DAC_IRQHandler()            __attribute__ ((weak, alias ("Default_Handler")));
void TIM7_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream0_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream1_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream2_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream3_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream4_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void ETH_IRQHandler()                 __attribute__ ((weak, alias ("Default_Handler")));
void ETH_WKUP_IRQHandler()            __attribute__ ((weak, alias ("Default_Handler")));
void CAN2_TX_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void CAN2_RX0_IRQHandler()            __attribute__ ((weak, alias ("Default_Handler")));
void CAN2_RX1_IRQHandler()            __attribute__ ((weak, alias ("Default_Handler")));
void CAN2_SCE_IRQHandler()            __attribute__ ((weak, alias ("Default_Handler")));
void OTG_FS_IRQHandler()              __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream5_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream6_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream7_IRQHandler()        __attribute__ ((weak, alias ("Default_Handler")));
void USART6_IRQHandler()              __attribute__ ((weak, alias ("Default_Handler")));
void I2C3_EV_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void I2C3_ER_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler()      __attribute__ ((weak, alias ("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler()       __attribute__ ((weak, alias ("Default_Handler")));
void OTG_HS_WKUP_IRQHandler()         __attribute__ ((weak, alias ("Default_Handler")));
void OTG_HS_IRQHandler()              __attribute__ ((weak, alias ("Default_Handler")));
void DCMI_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void RNG_IRQHandler()                 __attribute__ ((weak, alias ("Default_Handler")));
void FPU_IRQHandler()                 __attribute__ ((weak, alias ("Default_Handler")));
void UART7_IRQHandler()               __attribute__ ((weak, alias ("Default_Handler")));
void UART8_IRQHandler()               __attribute__ ((weak, alias ("Default_Handler")));
void SPI4_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void SPI5_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void SPI6_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void SAI1_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void LTDC_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void LTDC_ER_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void DMA2D_IRQHandler()               __attribute__ ((weak, alias ("Default_Handler")));
void SAI2_IRQHandler()                __attribute__ ((weak, alias ("Default_Handler")));
void QUADSPI_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void LPTIM1_IRQHandler()              __attribute__ ((weak, alias ("Default_Handler")));
void CEC_IRQHandler()                 __attribute__ ((weak, alias ("Default_Handler")));
void I2C4_EV_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void I2C4_ER_IRQHandler()             __attribute__ ((weak, alias ("Default_Handler")));
void SPDIF_RX_IRQHandler()            __attribute__ ((weak, alias ("Default_Handler")));


/* Interupt Vector array for stoing in memory */

void *vectors[] __attribute__((section(".isr_vector"), used)) = {
    (void *) &_estack,
	(void *) &Reset_Handler,
	(void *) &NMI_Handler,
	(void *) &HardFault_Handler,
	(void *) &MemManage_Handler,
	(void *) &BusFault_Handler,
	(void *) &UsageFault_Handler,
	0,
	0,
	0,
	0,
	(void *) &SVC_Handler,
	(void *) &DebugMon_Handler,
	0,
	(void *) &PendSV_Handler,
	(void *) &SysTick_Handler,
	(void *) &WWDG_IRQHandler,
	(void *) &PVD_IRQHandler,
	(void *) &TAMP_STAMP_IRQHandler,
	(void *) &RTC_WKUP_IRQHandler,
	(void *) &FLASH_IRQHandler,
	(void *) &RCC_IRQHandler,
	(void *) &EXTI0_IRQHandler,
	(void *) &EXTI1_IRQHandler,
	(void *) &EXTI2_IRQHandler,
	(void *) &EXTI3_IRQHandler,
	(void *) &EXTI4_IRQHandler,
	(void *) &DMA1_Stream0_IRQHandler,
	(void *) &DMA1_Stream1_IRQHandler,
	(void *) &DMA1_Stream2_IRQHandler,
	(void *) &DMA1_Stream3_IRQHandler,
	(void *) &DMA1_Stream4_IRQHandler,
	(void *) &DMA1_Stream5_IRQHandler,
	(void *) &DMA1_Stream6_IRQHandler,
	(void *) &ADC_IRQHandler,
	(void *) &CAN1_TX_IRQHandler,
	(void *) &CAN1_RX0_IRQHandler,
	(void *) &CAN1_RX1_IRQHandler,
	(void *) &CAN1_SCE_IRQHandler,
	(void *) &EXTI9_5_IRQHandler,
	(void *) &TIM1_BRK_TIM9_IRQHandler,
	(void *) &TIM1_UP_TIM10_IRQHandler,
	(void *) &TIM1_TRG_COM_TIM11_IRQHandler,
	(void *) &TIM1_CC_IRQHandler,
	(void *) &TIM2_IRQHandler,
	(void *) &TIM3_IRQHandler,
	(void *) &TIM4_IRQHandler,
	(void *) &I2C1_EV_IRQHandler,
	(void *) &I2C1_ER_IRQHandler,
	(void *) &I2C2_EV_IRQHandler,
	(void *) &I2C2_ER_IRQHandler,
	(void *) &SPI1_IRQHandler,
	(void *) &SPI2_IRQHandler,
	(void *) &USART1_IRQHandler,
	(void *) &USART2_IRQHandler,
	(void *) &USART3_IRQHandler,
	(void *) &EXTI15_10_IRQHandler,
	(void *) &RTC_Alarm_IRQHandler,
	(void *) &OTG_FS_WKUP_IRQHandler,
	(void *) &TIM8_BRK_TIM12_IRQHandler,
	(void *) &TIM8_UP_TIM13_IRQHandler,
	(void *) &TIM8_TRG_COM_TIM14_IRQHandler,
	(void *) &TIM8_CC_IRQHandler,
	(void *) &DMA1_Stream7_IRQHandler,
	(void *) &FMC_IRQHandler,
	(void *) &SDMMC1_IRQHandler,
	(void *) &TIM5_IRQHandler,
	(void *) &SPI3_IRQHandler,
	(void *) &UART4_IRQHandler,
	(void *) &UART5_IRQHandler,
	(void *) &TIM6_DAC_IRQHandler,
	(void *) &TIM7_IRQHandler,
	(void *) &DMA2_Stream0_IRQHandler,
	(void *) &DMA2_Stream1_IRQHandler,
	(void *) &DMA2_Stream2_IRQHandler,
	(void *) &DMA2_Stream3_IRQHandler,
	(void *) &DMA2_Stream4_IRQHandler,
	(void *) &ETH_IRQHandler,
	(void *) &ETH_WKUP_IRQHandler,
	(void *) &CAN2_TX_IRQHandler,
	(void *) &CAN2_RX0_IRQHandler,
	(void *) &CAN2_RX1_IRQHandler,
	(void *) &CAN2_SCE_IRQHandler,
	(void *) &OTG_FS_IRQHandler,
	(void *) &DMA2_Stream5_IRQHandler,
	(void *) &DMA2_Stream6_IRQHandler,
	(void *) &DMA2_Stream7_IRQHandler,
	(void *) &USART6_IRQHandler,
	(void *) &I2C3_EV_IRQHandler,
	(void *) &I2C3_ER_IRQHandler,
	(void *) &OTG_HS_EP1_OUT_IRQHandler,
	(void *) &OTG_HS_EP1_IN_IRQHandler,
	(void *) &OTG_HS_WKUP_IRQHandler,
	(void *) &OTG_HS_IRQHandler,
	(void *) &DCMI_IRQHandler,
	0,
	(void *) &RNG_IRQHandler,
	(void *) &FPU_IRQHandler,
	(void *) &UART7_IRQHandler,
	(void *) &UART8_IRQHandler,
	(void *) &SPI4_IRQHandler,
	(void *) &SPI5_IRQHandler,
	(void *) &SPI6_IRQHandler,
	(void *) &SAI1_IRQHandler,
	(void *) &LTDC_IRQHandler,
	(void *) &LTDC_ER_IRQHandler,
	(void *) &DMA2D_IRQHandler,
	(void *) &SAI2_IRQHandler,
	(void *) &QUADSPI_IRQHandler,
	(void *) &LPTIM1_IRQHandler,
	(void *) &CEC_IRQHandler,
	(void *) &I2C4_EV_IRQHandler,
	(void *) &I2C4_ER_IRQHandler,
	(void *) &SPDIF_RX_IRQHandler
};

#ifdef __cplusplus
}
#endif