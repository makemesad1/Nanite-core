/* External symbols, loaded from linker script */
#ifdef __cplusplus
extern "C" {
#endif

//STACK POINTER
extern void *_estack;

//DATA AND BSS SECTION INITIAZLIER;
extern void *_sidata, *_sdata, *_edata, *_sbss, *_ebss;

//DYNAMIC IRQ MECHANISM
extern void *_clbarr_ladr, *_clbarr_eadr;

#ifdef __cplusplus
//C++ GLOBAL CONSTRUCTOR
extern void (*__init_array_start)();
extern void (*__init_array_end)();
#endif

//Entry point
extern int main();

/* Default Handler */
void __attribute__((naked, noreturn)) Default_Handler(){

	for(;;);

}

/* Initializes Data section and bss */ 	

void __attribute__((naked, noreturn)) Reset_Handler()
{

	//Copy data
	void **pSource, **pDest;
	for (pSource = &_sidata, pDest = &_sdata; pDest != &_edata; pSource++, pDest++)
		*pDest = *pSource;

	//Fill bss with 0
	for (pDest = &_sbss; pDest != &_ebss; pDest++)
		*pDest = 0;

	//Fill in clbarr with default hanndler
	for (pDest = &_clbarr_ladr; pDest != &_clbarr_eadr; pDest++)
		*pDest = (void *) &Default_Handler;
	
	#ifdef __cplusplus
	//Construction loop
	for (void (**p)() = &__init_array_start; p < &__init_array_end; ++p) {
        (*p)();
    }
	#endif
	
	main();
	while(1);

}


/* Mechanism for dynamic irq handlers */


typedef void (*clb_ptr)();

static volatile clb_ptr clb_arr [228] __attribute__((section(".intclb"), used));

void register_irq_handler(int i, void (*func)(void)){
    clb_arr[i] = func;
}

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
    DMASTREAM6,
    ADC,
    CAN1_TX,
    CAN1_RX0,
    CAN1_RX1,
    CAN1_SCE,
    EXTI9_5,
    TIM1_BRK_TIM9,
    TIM1_UP_TIM10,
	TIM1_TRG_COM_TIM11, 
	TIM1_CC,            
	TIM2,  
	TIM3,  
	TIM4,  
	I2C1_EV,    
	I2C1_ER,   
	I2C2_EV,    
	I2C2_ER,   
	SPI1,     
	SPI2,     
	USART1,    
	USART2,      
	USART3,     
	EXTI15_10,     
	RTC_Alarm,     
	OTG_FS_WKUP,     
	TIM8_BRK_TIM12,   
	TIM8_UP_TIM13,     
	TIM8_TRG_COM_TIM14, 
	TIM8_CC,       
	DMA1_Stream7,   
	FMC,         
	SDMMC1,      
	TIM5,  
	SPI3,   
	UART4,   
	UART5,    
	TIM6_DAC,  
	TIM7,    
	DMA2_Stream0,   
	DMA2_Stream1,  
	DMA2_Stream2,   
	DMA2_Stream3,   
	DMA2_Stream4,   
	ETH,         
	ETH_WKUP,   
	CAN2_TX,    
	CAN2_RX0,   
	CAN2_RX1,   
	CAN2_SCE,   
	OTG_FS,   
	DMA2_Stream5,   
	DMA2_Stream6,  
	DMA2_Stream7,  
	USART6,     
	I2C3_EV,  
	I2C3_ER,  
	OTG_HS_EP1_OUT,   
	OTG_HS_EP1_IN,   
	OTG_HS_WKUP,   
	OTG_HS,     
	DCMI,  
	RNG,   
	FPU,   
	UART7,   
	UART8,  
	SPI4,   
	SPI5,   
	SPI6,    
	SAI1,   
	LTDC,   
	LTDC_ER,  
	DMA2D,   
	SAI2,    
	QUADSPI, 
	LPTIM1,   
	CEC,     
	I2C4_EV,  
	I2C4_ER,  
	SPDIF_RX 
};



static void NMI_Handler()
{
    clb_ptr clb = clb_arr[NMI];
    clb();
}

static void HardFault_Handler()
{
    clb_ptr clb = clb_arr[HARDFAULT];
    clb();
}

static void MemManage_Handler()
{
    clb_ptr clb = clb_arr[MEMMANGE];
    clb();
}

static void BusFault_Handler()
{
	clb_ptr clb = clb_arr[BUSFAULT];
    clb();
}

static void UsageFault_Handler()
{
	clb_ptr clb = clb_arr[USAGEFAULT];
    clb();
}

static void SVC_Handler()
{
	clb_ptr clb = clb_arr[SVCALL];
    clb();
}

static void DebugMon_Handler()
{
	clb_ptr clb = clb_arr[DEBUGMON];
    clb();
}

static void PendSV_Handler()
{
	clb_ptr clb = clb_arr[PENDSV];
    clb();
}

static void SysTick_Handler()
{
	clb_ptr clb = clb_arr[SYSTICK];
    clb();
}   

static void WWDG_IRQHandler()
{
	clb_ptr clb = clb_arr[WWDG];
    clb();
}   

static void PVD_IRQHandler()
{
	clb_ptr clb = clb_arr[PVD];
    clb();
}   

static void TAMP_STAMP_IRQHandler()
{
	clb_ptr clb = clb_arr[TAMPSTAMP];
    clb();
}   

static void RTC_WKUP_IRQHandler()
{
	clb_ptr clb = clb_arr[RTCWAKEUP];
    clb();
}   

static void FLASH_IRQHandler()
{
	clb_ptr clb = clb_arr[FLASH];
    clb();
}   

static void RCC_IRQHandler()
{
	clb_ptr clb = clb_arr[RCC];
    clb();
}   

static void EXTI0_IRQHandler()
{
	clb_ptr clb = clb_arr[EXTI0];
    clb();
}   

static void EXTI1_IRQHandler()
{
	clb_ptr clb = clb_arr[EXTI1];
    clb();
}   

static void EXTI2_IRQHandler()
{
	clb_ptr clb = clb_arr[EXTI2];
    clb();
}   

static void EXTI3_IRQHandler()
{
	clb_ptr clb = clb_arr[EXTI3];
    clb();
}   

static void EXTI4_IRQHandler()
{
	clb_ptr clb = clb_arr[EXTI4];
    clb();
}   

static void DMA1_Stream0_IRQHandler()
{
	clb_ptr clb = clb_arr[DMASTREAM0];
    clb();
}   

static void DMA1_Stream1_IRQHandler()
{
	clb_ptr clb = clb_arr[DMASTREAM1];
    clb();
}   

static void DMA1_Stream2_IRQHandler()
{
	clb_ptr clb = clb_arr[DMASTREAM2];
    clb();
}   

static void DMA1_Stream3_IRQHandler()
{
	clb_ptr clb = clb_arr[DMASTREAM3];
    clb();
}   

static void DMA1_Stream4_IRQHandler()
{
	clb_ptr clb = clb_arr[DMASTREAM4];
    clb();
}   

static void DMA1_Stream5_IRQHandler()
{
	clb_ptr clb = clb_arr[DMASTREAM5];
    clb();
}   

static void DMA1_Stream6_IRQHandler()
{
	clb_ptr clb = clb_arr[DMASTREAM6];
    clb();
}   

static void ADC_IRQHandler()    
{
	clb_ptr clb = clb_arr[ADC];
    clb();
}   

static void CAN1_TX_IRQHandler() 
{
	clb_ptr clb = clb_arr[CAN1_TX];
    clb();
}   

static void CAN1_RX0_IRQHandler() 
{
	clb_ptr clb = clb_arr[CAN1_RX0];
    clb();
}   

static void CAN1_RX1_IRQHandler() 
{
	clb_ptr clb = clb_arr[CAN1_RX1];
    clb();
}   

static void CAN1_SCE_IRQHandler() 
{
	clb_ptr clb = clb_arr[CAN1_SCE];
    clb();
}   

static void EXTI9_5_IRQHandler() 
{
	clb_ptr clb = clb_arr[EXTI9_5];
    clb();
}   

static void TIM1_BRK_TIM9_IRQHandler()
{
	clb_ptr clb = clb_arr[TIM1_BRK_TIM9];
    clb();
}   

static void TIM1_UP_TIM10_IRQHandler()
{
	clb_ptr clb = clb_arr[TIM1_UP_TIM10];
    clb();
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

/* Interupt Vector array for stoing in memory */

static void *vectors[] __attribute__((section(".isr_vector"), used)) = {
	
	(void *)&_estack,
	(void *)&Reset_Handler,
	(void *)&NMI_Handler,
	(void *)&HardFault_Handler,
	(void *)&MemManage_Handler,
	(void *)&BusFault_Handler,
	(void *)&UsageFault_Handler,
	0,
	0,
	0,
	0,
	(void *)&SVC_Handler,
	(void *)&DebugMon_Handler,
	0,
	(void *)&PendSV_Handler,
	(void *)&SysTick_Handler,
	(void *)&WWDG_IRQHandler,
	(void *)&PVD_IRQHandler,
	(void *)&TAMP_STAMP_IRQHandler,
	(void *)&RTC_WKUP_IRQHandler,
	(void *)&FLASH_IRQHandler,
	(void *)&RCC_IRQHandler,
	(void *)&EXTI0_IRQHandler,
	(void *)&EXTI1_IRQHandler,
	(void *)&EXTI2_IRQHandler,
	(void *)&EXTI3_IRQHandler,
	(void *)&EXTI4_IRQHandler,
	(void *)&DMA1_Stream0_IRQHandler,
	(void *)&DMA1_Stream1_IRQHandler,
	(void *)&DMA1_Stream2_IRQHandler,
	(void *)&DMA1_Stream3_IRQHandler,
	(void *)&DMA1_Stream4_IRQHandler,
	(void *)&DMA1_Stream5_IRQHandler,
	(void *)&DMA1_Stream6_IRQHandler,
	(void *)&ADC_IRQHandler,
	(void *)&CAN1_TX_IRQHandler,
	(void *)&CAN1_RX0_IRQHandler,
	(void *)&CAN1_RX1_IRQHandler,
	(void *)&CAN1_SCE_IRQHandler,
	(void *)&EXTI9_5_IRQHandler,
	(void *)&TIM1_BRK_TIM9_IRQHandler,
	(void *)&TIM1_UP_TIM10_IRQHandler,
	(void *)&TIM1_TRG_COM_TIM11_IRQHandler,
	(void *)&TIM1_CC_IRQHandler,
	(void *)&TIM2_IRQHandler,
	(void *)&TIM3_IRQHandler,
	(void *)&TIM4_IRQHandler,
	(void *)&I2C1_EV_IRQHandler,
	(void *)&I2C1_ER_IRQHandler,
	(void *)&I2C2_EV_IRQHandler,
	(void *)&I2C2_ER_IRQHandler,
	(void *)&SPI1_IRQHandler,
	(void *)&SPI2_IRQHandler,
	(void *)&USART1_IRQHandler,
	(void *)&USART2_IRQHandler,
	(void *)&USART3_IRQHandler,
	(void *)&EXTI15_10_IRQHandler,
	(void *)&RTC_Alarm_IRQHandler,
	(void *)&OTG_FS_WKUP_IRQHandler,
	(void *)&TIM8_BRK_TIM12_IRQHandler,
	(void *)&TIM8_UP_TIM13_IRQHandler,
	(void *)&TIM8_TRG_COM_TIM14_IRQHandler,
	(void *)&TIM8_CC_IRQHandler,
	(void *)&DMA1_Stream7_IRQHandler,
	(void *)&FMC_IRQHandler,
	(void *)&SDMMC1_IRQHandler,
	(void *)&TIM5_IRQHandler,
	(void *)&SPI3_IRQHandler,
	(void *)&UART4_IRQHandler,
	(void *)&UART5_IRQHandler,
	(void *)&TIM6_DAC_IRQHandler,
	(void *)&TIM7_IRQHandler,
	(void *)&DMA2_Stream0_IRQHandler,
	(void *)&DMA2_Stream1_IRQHandler,
	(void *)&DMA2_Stream2_IRQHandler,
	(void *)&DMA2_Stream3_IRQHandler,
	(void *)&DMA2_Stream4_IRQHandler,
	(void *)&ETH_IRQHandler,
	(void *)&ETH_WKUP_IRQHandler,
	(void *)&CAN2_TX_IRQHandler,
	(void *)&CAN2_RX0_IRQHandler,
	(void *)&CAN2_RX1_IRQHandler,
	(void *)&CAN2_SCE_IRQHandler,
	(void *)&OTG_FS_IRQHandler,
	(void *)&DMA2_Stream5_IRQHandler,
	(void *)&DMA2_Stream6_IRQHandler,
	(void *)&DMA2_Stream7_IRQHandler,
	(void *)&USART6_IRQHandler,
	(void *)&I2C3_EV_IRQHandler,
	(void *)&I2C3_ER_IRQHandler,
	(void *)&OTG_HS_EP1_OUT_IRQHandler,
	(void *)&OTG_HS_EP1_IN_IRQHandler,
	(void *)&OTG_HS_WKUP_IRQHandler,
	(void *)&OTG_HS_IRQHandler,
	(void *)&DCMI_IRQHandler,
	0,
	(void *)&RNG_IRQHandler,
	(void *)&FPU_IRQHandler,
	(void *)&UART7_IRQHandler,
	(void *)&UART8_IRQHandler,
	(void *)&SPI4_IRQHandler,
	(void *)&SPI5_IRQHandler,
	(void *)&SPI6_IRQHandler,
	(void *)&SAI1_IRQHandler,
	(void *)&LTDC_IRQHandler,
	(void *)&LTDC_ER_IRQHandler,
	(void *)&DMA2D_IRQHandler,
	(void *)&SAI2_IRQHandler,
	(void *)&QUADSPI_IRQHandler,
	(void *)&LPTIM1_IRQHandler,
	(void *)&CEC_IRQHandler,
	(void *)&I2C4_EV_IRQHandler,
	(void *)&I2C4_ER_IRQHandler,
	(void *)&SPDIF_RX_IRQHandler
};

#ifdef __cplusplus
}
#endif