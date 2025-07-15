; -----------------------------------------------------------------------------
; Score Management Subroutines
; -----------------------------------------------------------------------------
; This file contains subroutines for managing player scores.
; It operates on the global score variables defined in globals.inc.

.segment "CODE"

; =============================================================================
; Player 1 Score Management
; =============================================================================

; -----------------------------------------------------------------------------
; reset_player1_score
; Description: Resets Player 1's score to zero.
; Input:       None
; Output:      None
; Modifies:    A, player1_score
; -----------------------------------------------------------------------------
reset_player1_score:
    lda #$00
    sta player1_score
    sta player1_score+1
    sta player1_score+2
    rts

; -----------------------------------------------------------------------------
; add_to_player1_score
; Description: Adds the value in the accumulator to Player 1's 24-bit score.
; Input:       A - The 8-bit value to add.
; Output:      None
; Modifies:    A, player1_score
; -----------------------------------------------------------------------------
add_to_player1_score:
    clc                     ; Clear carry before starting addition.
    adc player1_score       ; Add the value to the low byte of the score.
    sta player1_score       ; Store the new low byte.

    lda player1_score+1     ; Load the middle byte.
    adc #$00                ; Add 0 + the carry from the previous addition.
    sta player1_score+1     ; Store the new middle byte.

    lda player1_score+2     ; Load the high byte.
    adc #$00                ; Add 0 + the carry from the middle byte addition.
    sta player1_score+2     ; Store the new high byte.
    rts

; =============================================================================
; Player 2 Score Management
; =============================================================================

; -----------------------------------------------------------------------------
; reset_player2_score
; Description: Resets Player 2's score to zero.
; Input:       None
; Output:      None
; Modifies:    A, player2_score
; -----------------------------------------------------------------------------
reset_player2_score:
    lda #$00
    sta player2_score
    sta player2_score+1
    sta player2_score+2
    rts

; -----------------------------------------------------------------------------
; add_to_player2_score
; Description: Adds the value in the accumulator to Player 2's 24-bit score.
; Input:       A - The 8-bit value to add.
; Output:      None
; Modifies:    A, player2_score
; -----------------------------------------------------------------------------
add_to_player2_score:
    clc
    adc player2_score
    sta player2_score

    lda player2_score+1
    adc #$00
    sta player2_score+1

    lda player2_score+2
    adc #$00
    sta player2_score+2
    rts
