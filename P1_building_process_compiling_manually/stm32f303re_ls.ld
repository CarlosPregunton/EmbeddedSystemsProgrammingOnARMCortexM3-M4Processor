ENTRY(Reset_Handler)

MEMORY
{
	FLASH(rx):ORIGIN=0x08000000,LENGTH=1024K
	SRAM(rwx):ORIGIN=0x20000000,LENGTH=128
}
SECTIONS
{
    .text :
    {
    // Merge .isr_vector, .text sections and .rodata of all input files
    	*(.isr_vector)
	*(.text)
    	*(.rodata)	
    }> FLASH AT> FLASH
		
    .data
    {
    	*(.data)
    }> SRAM AT> FLASH
    
    .bss
    {
    	*(.bss)
    }> SRAM
}
	
