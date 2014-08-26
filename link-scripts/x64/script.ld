SECTIONS {

  . = 0x8000000000;

  .text BLOCK(16) : ALIGN(16) {
    *(.libentryinit)
    
    _libentry_inits_start = .;
    *(.ctors)
    *(.init_array)
    _libentry_inits_end = .;
    
    _libentry_deinits_start = .;
    *(.dtors)
    *(.fini_array)
    _libentry_deinits_end = .;
    
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