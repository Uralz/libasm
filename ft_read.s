            global _ft_read
            section .text
            extern ___error
_ft_read:
            mov     rax, 0x2000003      ;put "read" syscall number
            syscall
            jnc    .finish		;check carry flag, 0 if no errors
            mov     rdi, rax    ;save errno to rdi
            call    ___error    ;get errno addr to rax
            mov     [rax], rdi  ;set errno
            mov     rax, -1     ;return -1 
.finish:
            ret