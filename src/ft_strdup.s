            global ft_strdup
            section .text
            extern ft_strlen
            extern malloc
            extern ft_strcpy
            extern __errno_location
ft_strdup:
            call    ft_strlen       ;put src length to rax 
            inc     rax             ;inrement rax to call malloc correctly
            push    rdi             ;save addres of src
            mov     rdi, rax        ;prepare arg for calling malloc
            call    malloc          ;now rax contains addres of dest
            cmp     rax, 0          ;error detectd if rax == 0
            je      .err
            pop     rdi             ;get back addres of src
            mov     rsi, rdi        ;make src as 2nd arg of ft_strcpy
            mov     rdi, rax        ;make dest as 1st arg of ft_strcpy
            call    ft_strcpy       ;copy src to dest
            jmp     .finish
.err:       
            call __errno_location
            mov     qword [rax], 12
            mov     rax, 0
.finish:
            ret                     ;return dest addres or 0 if malloc error detected
