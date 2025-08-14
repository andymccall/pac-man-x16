; -----------------------------------------------------------------------------
; Player Management Subroutines
; -----------------------------------------------------------------------------
; This file contains subroutines for managing the player state.

.segment "CODE"

; -----------------------------------------------------------------------------
; select_player
; Description: Placeholder for the player selection logic.
;              This routine will handle the logic for selecting between
;              1-player and 2-player modes.
; Input:       None
; Output:      None
; Modifies:    -
; -----------------------------------------------------------------------------
select_player:
<<<<<<< HEAD
    jsr GETIN_NB            ; Non-blocking call to get a character from the keyboard buffer.
    beq no_key_pressed      ; If no key was pressed (A=0), branch to the end.

    cmp #'1'                ; Was the '1' key pressed?
    beq add_p1_credit       ; If so, branch to add a credit for Player 1.

    cmp #'2'                ; Was the '2' key pressed?
    beq add_p2_credit       ; If so, branch to add a credit for Player 2.

    cmp #'s'                ; Was the 's' key pressed?
    beq start_game          ; If so, branch to the start game stub.

    cmp #'q'                ; Was the 'q' key pressed?
    bne no_key_pressed      ; If not, branch to the end
    jmp quit                ; If so, jump to the quit routine in main.asm.

no_key_pressed:
    rts                     ; Return if no relevant key was pressed.

add_p1_credit:
    jsr add_player1_credit  ; Call the subroutine to add a credit for Player 1.
    jsr show_player1_credited_message
    rts

add_p2_credit:
    jsr add_player2_credit  ; Call the subroutine to add a credit for Player 2.
    jsr show_player2_credited_message
    rts

start_game:
    ; TODO: Implement game start logic.
    rts
=======
    ; TODO: Implement player selection logic.
    rts                     ; Return from subroutine
>>>>>>> main
