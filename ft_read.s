            global ft_read
            section .text
ft_read:
            mov     rax, 0      ;put "read" syscall number
            syscall
            cmp     rax, 0      ;check if error (then rax < 0)
            jge     .finish
            mov     rax, -1     ;return -1 if error
.finish:
            ret