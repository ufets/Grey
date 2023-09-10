bits 64

section .data
section .text
global func_asm:
func_asm:
    align 16
    push rbp
    mov rbp, rsp
    ;mov ecx, dword[rbp + 4]
    add r8, rdi
.work:
    cmp rdi, r8
    je .exit
    xor rax, rax

    mov al, byte[rdi]
    cvtsi2ss xmm3, eax
    mulss xmm3, xmm0

    ;xor al, al
    mov al, byte[rdi + 1]
    cvtsi2ss xmm4, eax
    mulss xmm4, xmm1

    addss xmm3, xmm4
    
    ;xor al, al
    mov al, byte[rdi + 2]
    cvtsi2ss xmm4, eax
    mulss xmm4, xmm2

    addss xmm3, xmm4

    cvtss2si eax, xmm3
    mov byte[rsi], al
    cmp dx, 4
    jne .adding
    ;xor al,al
    mov al, byte[rdi + 3]
    mov byte[rsi + 1], al
;________________________________________
.adding:
    add rdi, rdx
    add rsi, rcx
    jmp .work
.exit:
    ;mov rax, r8
    leave
    ret