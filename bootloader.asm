ORG 0
BITS 16

jmp 0x7c0:start

start:

; Initialize the stack and segment registers
    cli
    mov ax, 0x7C0
    mov ds, ax
    mov es, ax
    mov ax, 0x00
    mov ss, ax
    mov sp, 0x7C00 
    sti

; clear the screen
    mov ah,00h
    mov al, 03h
    int 0x10

;store amt of memory in ax
;    mov ah, 0x12
;   int 0x12

; print stuff

    call printax

    mov si, separator
    call print

    call newline

    mov si, message
    call print

    ; jmp $

    cli
    mov ax, 0x1000
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00
    sti

    jmp ox1000:0

;print word
print:
    mov bx, 0
.loop:
    lodsb
    cmp al, 0
    je .done
    call print_char
    jmp .loop
.done:
    ret

;print character
print_char:
    mov ah, 0eh
    int 0x10
    ret

;print newline
newline:
    mov ah, 0x0E
    mov al, 0x0D
    int 0x10
    mov al, 0x0A
    int 0x10
    ret

;number to ascii AX printing
printax:
    mov bx, 10
    mov cx, 0
    .loop:
        mov dx, 0
        div bx
        push dx
        inc cx
        test ax, ax
        jnz .loop

    .print_loop:
        pop dx
        add dx, '0'
        mov al, dl
        call print_char
        loop .print_loop
    ret

message: db "Sidak's Bootloader", 0
separator: db "-------------------------", 0
memory: db "Memory: ", 0
cpu: db "type: x86", 0
mode: db "Mode: 16 bit Real Mode", 0

times 510-($ - $$) db 0
dw 0xAA55