
MEMORY{
	/* RAM REGIONS */
	RAM_ITCM (rxw)	: ORIGIN = 0x0, 	   LENGTH = 16K
	RAM_DTCM (rw)	: ORIGIN = 0x20000000, LENGTH = 64K
	SRAM1 (rwx) 	: ORIGIN = 0x20010000, LENGTH = 240K
	SRAM2 (rwx) 	: ORIGIN = 0x2004C000, LENGTH = 16K

	/* FLASH REGION */
	FLASH_AXIM(rx)  : ORIGIN = 0x08000000, LENGTH = 1M
	FLASH_ITCM(rx)	: ORIGIN = 0x00200000, LENGTH = 1M
	
}

_estack = LENGTH(SRAM1) + ORIGIN(SRAM1);

SECTIONS{

	/* 	Default vector section that goes to FLASH_AXIM (flash_AXIM)
	 * 	Vectors wil be stored at 0x80000000 and will not be a weak handlers
	 * 	Defaulting will happen in ram via callback, this allows me to overwrite any registered callback for a handler
	 *  Maybe an ability to pass reg struct will be added toa  callback. which is kinda cool, or a pointer in constant memory location, will see
	 */

	.isr_vector : {
		_isr_vec_ladr = .;
		KEEP(*(.isr_vector))
		_isr_vec_eadr = .;
	} >FLASH_AXIM
	/* END OF VECTORS */

	
	/* Text section */
	/* All boot code goes here */
	/* TEXT with offset to isr vecotr but in deffrent memory region, true harvard layout */
	.text (ORIGIN(FLASH_ITCM) + SIZEOF(.isr_vector)): {
        . = ALIGN(4);
        *(.text)
    } AT>FLASH_AXIM
	/* END OF TEXT */

	
	/* DATA AND BSS SECTION */
	/* DATA will copied to SRAM1 and BSS will will be initiazlied to 0 */
	_sidata = LOADADDR(.data);
    .data : {
		. = ALIGN(4);
		_sdata = .;
		*(.data)
		. = ALIGN(4);
		_edata = .;
	} >SRAM1 AT>FLASH_AXIM
	
	.bss : {
		. = ALIGN(4);
		_sbss = .;
		*(.bss)
		. = ALIGN(4);
		_ebss = .;
	} >SRAM1


	/* VECTORs in ram for dynamic vector assigment, goes right after bss section, so take care when writing to global arrays can overwrite the intclb sector */
	.intclb : {
		. = ALIGN(4);
		_clbarr_ladr = .;
		KEEP(*(.intclb))
		_clbarr_eadr = .;
	} >SRAM1
}

/* Work on more exact memory map */