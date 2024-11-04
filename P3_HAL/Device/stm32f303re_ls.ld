ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
  SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
  .isr_vector :
  {
    KEEP(*(.isr_vector))
  } >FLASH
  
  .text :
  {
    . = ALIGN(4);
    *(.text)
    *(.rodata)
    . = ALIGN(4);
    _etext = .;
  } >FLASH
    
  .data :
  { 
    . = ALIGN(4);
    _sdata = .; 
    *(.data)
    . = ALIGN(4);
    _edata = .;
  } >SRAM AT> FLASH
    
  .bss :
  { 
    . = ALIGN(4);  
    _sbss = .;
    *(.bss)
    . = ALIGN(4);
    _ebss = .;
  } >SRAM
}

/* ENTRY command is used to set the "Entry point address" information
in the header of final elf file generated. That is useful for debugging
purposes*/

/* MEMORY command allows you to describe the different memories present in
the target and their start address and size information.
The linker uses information mentioned in this command to assign addresses 
to merged sections (process known as relocation) */

/* SECTIONS command is used to create different output sections in the final
elf executable generated.
Important command by which you can instruct the linker how to merge the input sections to yield an output section.
This command also controls the order in which different output sections appear
in the elf file generated.
You also mention the placement of a section in a memory region.*/

/* isr_vector merge each section of all files and place flash memory region, 
   placing the first section written on the lowest memory region */
   
/* .data section merge .data section of all files and place on a FLASH region then,
   relocate it to SRAM. */	

/* .bss section merge all files and place on a SRAM region. */	    

/*IMPORTANT NOTE: Location counter (.) always tracks VMA, NOT LMA */
/*ALIGN(4) command aligns sections to 32 bit (1 word)*/
