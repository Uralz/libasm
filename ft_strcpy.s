            global _ft_strcpy
            section .text
_ft_strcpy:
            xor     rcx, rcx                ;set rcx (counter) to zero
.loop:
            mov     al, [rsi + rcx]         ;copy symbol from src to al register (low rax)
            cmp     al, 0                   ;compare src symbol with 0 (end of line)
            je      .finish                 ;finish if equal (reach the end of src line)
            mov     [rdi + rcx], al         ;move symbol from register to dest
            inc     rcx                     ;increment counter (rcx)
            jmp     .loop                   ;doing cycle
.finish:
            mov     [rdi + rcx], byte 0     ;put zero to terminate dest line correctly
            mov     rax, rdi                ;put dest addr to rax for return
            ret