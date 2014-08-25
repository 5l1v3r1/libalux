section .libaluxinit

extern libalux_main

libalux_entry_point:
  mov rsp, temporaryStack.bottom
  call libalux_main
  ; never reached

; 16 KB temporary stack
align 16
temporaryStack:
  times 0x4000 db 0
.bottom: