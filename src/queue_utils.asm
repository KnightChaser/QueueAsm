; src/queue_utils.asm
%include "src/structs.inc"

global queue_count
global queue_is_empty
global queue_peek

extern exit

section .text
;------------------------------------------------------------------------------
; long queue_count(Queue *q)
;   – returns q->count
; Args:
;   RDI = pointer to Queue
; Returns:
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
; Args:
;   RDI = pointer to Queue
; Returns:
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

;------------------------------------------------------------------------------
;int64_t queue_peek(Queue *q)
;    – returns the value at the front without removing it
; Args:
;   RDI = pointer to Queue
; Returns:
;   RAX = value at the front, or exits(1) on underflow
;------------------------------------------------------------------------------
queue_peek:
    push    rbp
    mov     rbp, rsp

    mov     rax, [rdi + QUEUE_FRONT]
    test    rax, rax
    je      .underflow

    mov     rax, [rax + NODE_DATA]   ; Load the data from the front node
    pop     rbp
    ret

.underflow:
    mov     edi, 1
    call    exit
