; -----------------------------------------------------------------------------
; Credits Management Subroutines
; -----------------------------------------------------------------------------
; This file contains subroutines for managing player credits.
; It operates on the global credit variables defined in globals.inc.

.segment "CODE"

; -----------------------------------------------------------------------------
; add_player1_credit
; Description: Increments the credit count for Player 1.
; Input:       None
; Output:      None
; Modifies:    A, player1_credits
; -----------------------------------------------------------------------------
add_player1_credit:
    inc player1_credits     ; Increment the credit count for player 1
    rts                     ; Return from subroutine

; -----------------------------------------------------------------------------
; use_player1_credit
; Description: Decrements the credit count for Player 1 if credits are available.
; Input:       None
; Output:      Carry flag set if a credit was used, clear if no credits were available.
; Modifies:    A, player1_credits
; -----------------------------------------------------------------------------
use_player1_credit:
    lda player1_credits     ; Load player 1's credits into the accumulator
    beq no_credits_p1       ; If zero, branch to no_credits

    dec player1_credits     ; Decrement the credit count
    sec                     ; Set carry to indicate success
    rts

no_credits_p1:
    clc                     ; Clear carry to indicate failure (no credits)
    rts
