SECTIONS {

  . = 0x8000000000;

  .text BLOCK(16) : ALIGN(16) {
    *(.libaluxinit)
    
    _libalux_inits_start = .;
    *(.ctors)
    *(.init_array)
    _libalux_inits_end = .;
    
    _libalux_deinits_start = .;
    *(.dtors)
    *(.fini_array)
    _libalux_deinits_end = .;
    
    *(.text)
  }
  
  .bss BLOCK(16) : ALIGN(16) {
    *(.bss)
  }
  
  .rodata BLOCK(16) : ALIGN(16) {
    *(.rodata)
  }
  
  .data BLOCK(16) : ALIGN(16) {
    *(.data)
    *(COMMON)
    *(.bss)
  }
  
}