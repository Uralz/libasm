            global ft_write
            section .text
ft_write:
            mov     rax, 1      ;put "write" syscall number
            syscall
            cmp     rax, 0      ;check if error (then rax < 0)
            jge     .finish
            mov     rax, -1     ;return -1 if error
.finish:
            ret