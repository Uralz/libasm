            global _ft_strcmp
            section .text
_ft_strcmp:
            xor     rcx, rcx                ;set rcx (counter) to zero
            xor     rax, rax                ;set rax to zero
            xor     rdx, rdx                ;set rdx to zero
.loop:
            mov     al, [rdi + rcx]         ;put 1 byte char from str1 to low rax
            mov     dl, [rsi + rcx]         ;put 1 byte char from str2 to low rdx
            sub     rax, rdx                ;subtract symbols str1 - str2
            cmp     byte [rdi + rcx], 0     ;str1 EOL check
            je      .finish                 ;if EOL - finish and return diff
            cmp     byte [rsi + rcx], 0     ;str2 EOL check
            je      .finish                 ;if EOL - finish and return diff
            cmp     rax, 0                  ;check result is zero
            jne     .finish                 ;if difference - finish and return diff
            inc     rcx                     ;if ok, continue comparing
            jmp     .loop        
.finish:
            ret