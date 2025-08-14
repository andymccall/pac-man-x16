; -----------------------------------------------------------------------------
; UI and Text Display Subroutines
; -----------------------------------------------------------------------------
; This file contains subroutines for displaying game information on the screen.

.segment "CODE"

; -----------------------------------------------------------------------------
; print_byte
; Description: Prints the decimal value of a byte stored in the accumulator.
;              Handles values from 0 to 255. Suppresses leading zeros.
; Input:       A - The byte to print.
; Output:      None
; Modifies:    A, X, Y
; -----------------------------------------------------------------------------
print_byte:
    pha                     ; Save A
    ldx #0                  ; Flag for leading zeros, 0=print
    
    sec                     ; Set carry for subtraction
    sbc #100                ; Subtract 100
    bcs @hundreds_loop      ; If A >= 100, handle hundreds
    
    clc                     ; Clear carry
    adc #100                ; Add 100 back to get original value
    ldx #1                  ; Set flag to suppress leading zero

@hundreds_loop:
    iny                     ; Increment hundreds digit
    sbc #100                ; Subtract 100
    bcs @hundreds_loop      ; Loop until less than 100
    
    clc
    adc #100
    
    tya                     ; Transfer hundreds digit to A
    ora #$30                ; Convert to ASCII
    cpx #1                  ; Check suppress zero flag
    beq @skip_hundreds      ; If flag is set, skip printing
    jsr CHROUT
@skip_hundreds:
    
    pla                     ; Restore A (with remainder from hundreds)
    pha                     ; Save it again
    ldx #0                  ; Reset Y for tens digit
    
    sec
    sbc #10
    bcs @tens_loop
    
    clc
    adc #10
    ldx #1
    
@tens_loop:
    iny
    sbc #10
    bcs @tens_loop
    
    clc
    adc #10
    
    tya
    ora #$30
    cpx #1
    beq @skip_tens
    jsr CHROUT
@skip_tens:

    pla                     ; Restore final remainder (units digit)
    ora #$30                ; Convert to ASCII
    jsr CHROUT
    
    rts

; -----------------------------------------------------------------------------
; show_player1_credited_message
; Description: Displays a confirmation message and the current credit total for Player 1.
; -----------------------------------------------------------------------------
show_player1_credited_message:
    br_text_print player1_credited_msg
    br_text_print player1_credits_msg
    lda player1_credits
    jsr print_byte
    rts

; -----------------------------------------------------------------------------
; show_player2_credited_message
; Description: Displays a confirmation message and the current credit total for Player 2.
; -----------------------------------------------------------------------------
show_player2_credited_message:
    br_text_print player2_credited_msg
    br_text_print player2_credits_msg
    lda player2_credits
    jsr print_byte
    rts

.segment "RODATA"

; --- UI Messages ---
player1_credited_msg:   .asciiz "Player 1 Credited!"
player1_credits_msg:    .asciiz "Player 1 credits: "
player2_credited_msg:   .asciiz "Player 2 Credited!"
player2_credits_msg:    .asciiz "Player 2 credits: "
