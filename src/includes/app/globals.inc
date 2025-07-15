; -----------------------------------------------------------------------------
; Global Variables
; -----------------------------------------------------------------------------
; This file contains global variables that are accessible throughout the game.
; These variables are defined in the BSS (Block Started by Symbol) segment,
; which is used for uninitialized data.

.segment "BSS"

; Player Credits
; -----------------------------------------------------------------------------
; These variables store the number of credits for each player.
player1_credits:    .res 1  ; 1 byte for Player 1's credits.
player2_credits:    .res 1  ; 1 byte for Player 2's credits.

; Player Scores
; -----------------------------------------------------------------------------
; These variables store the scores for each player.
; A 3-byte value is used for each score, allowing for scores up to 16,777,215.
player1_score:      .res 3  ; 3 bytes for Player 1's score.
player2_score:      .res 3  ; 3 bytes for Player 2's score.

; Active Player
; -----------------------------------------------------------------------------
; This variable stores the currently active player (e.g., 1 or 2).
active_player:      .res 1  ; 1 byte for the active player.
