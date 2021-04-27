            global _ft_strlen
            section .text
_ft_strlen: 
            xor rax, rax            ;set count value (rax) to zero
.loop:
            cmp byte [rdi + rax], 0 ;compare current symbol with zero (end of line)
            je .finish              ;exit if found
            inc rax                 ;increment counter if not
            jmp .loop               ;and repeat
.finish:
            ret                     ;return value (rax)