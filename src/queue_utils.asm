; src/queue_utils.asm
%include "src/structs.inc"

global queue_count
global queue_is_empty

section .text
;------------------------------------------------------------------------------
; long queue_count(Queue *q)
;   – returns q->count
;   RDI = pointer to Queue
;   RAX = count
;------------------------------------------------------------------------------
queue_count:
    push    rbp
    mov     rbp, rsp
    mov     rax, [rdi + Queue.count]  ; Load the count from the Queue structure
    pop     rbp
    ret

;------------------------------------------------------------------------------
; int queue_is_empty(Queue *q)
;   – returns 1 if empty, 0 otherwise
;   RDI = pointer to Queue
;   RAX = 1 or 0
;------------------------------------------------------------------------------
queue_is_empty:
    push    rbp
    mov     rbp, rsp
    mov     rax, [rdi + QUEUE_COUNT]
    test    rax, rax                ; Check if count is zero
    setz    al                      ; Set AL to 1 if zero, 0 otherwise
    movzx   rax, al                 ; Zero-extend AL to RAX
    pop     rbp
    ret
