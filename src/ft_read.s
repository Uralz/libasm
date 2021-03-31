            global ft_read
            section .text
            extern __errno_location
ft_read:
            mov     rax, 0      ;put "read" syscall number
            syscall
            cmp     rax, 0      ;check if error (then rax < 0)
            jge    .finish
            neg     rax         ;make errno positive
            mov     rdi, rax    ;save errno to rdi
            call    __errno_location    ;get errno addr to rax
            mov     [rax], rdi  ;set errno
            mov     rax, -1     ;return -1 
.finish:
            ret