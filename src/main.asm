;
; Title:        Pac-Man X16
;
; Description:  Main entry point for the Pac-Man X16 game.
;               This file handles program initialization, the main game loop,
;               and program termination.
; Author:		Andy McCall, mailme@andymccall.co.uk, others welcome!
;
; Created:		2025-07-15 @ 17:28
; Last Updated:	2025-07-15 @ 17:28
;
; Modinfo:

; -----------------------------------------------------------------------------
; Segment Definitions
; -----------------------------------------------------------------------------
; These segments are used by the linker to organize the code and data in memory.
.segment "STARTUP"  ; For code that runs at program startup.
.segment "INIT"     ; For one-time initialization code.
.segment "ONCE"     ; For code that runs only once.

.segment "CODE"     ; Main code segment.

; -----------------------------------------------------------------------------
; Program Entry Point
; -----------------------------------------------------------------------------
   jmp start        ; Jump to the main program logic.

; -----------------------------------------------------------------------------
; Includes
; -----------------------------------------------------------------------------
; API includes provide access to the Commander X16's hardware and kernal functions.
   .include "includes/api/br_equates.inc"   ; General equates and constants.
   .include "includes/api/br_text.inc"      ; Text rendering functions.
   .include "includes/api/br_screen.inc"    ; Screen and graphics mode functions.
   .include "includes/api/br_mouse.inc"     ; Mouse handling functions.

; App includes for game-specific code would go here.
   .include "includes/app/globals.inc"
   .include "includes/app/credits.inc"
   .include "includes/app/scoring.inc"
   .include "includes/app/player.inc"

; -----------------------------------------------------------------------------
; Main Program Logic
; -----------------------------------------------------------------------------
start:

    ; --- Initialization ---
    br_text_print welcome_string    ; Display a welcome message on the screen.

    br_mouse_hide                   ; Hide the mouse cursor.

    jsr GRAPH_init                  ; Initialize the graphics system.

    br_screen_set_mode SCREEN_MODE_320X240_256C ; Set the screen to 320x240 with 256 colors.

    ; Set the drawing colors.
    lda #$00             ; Stroke color (for lines and outlines).
    ldx #$00             ; Fill color (for filled shapes).
    ldy #$00             ; Background color.
    jsr GRAPH_set_colors ; Call the graphics routine to set the colors.
   
    jsr GRAPH_clear      ; Clear the graphics screen with the background color.

    ; --- Initialize Game State ---
    ; Reset scores and credits for both players to zero at the start of the game.
    jsr reset_player1_score
    jsr reset_player2_score

    lda #$00
    sta player1_credits
    sta player2_credits

    ; Initialize active_player to default value (Player 1).
    lda #$01
    sta active_player
; -----------------------------------------------------------------------------
; Main Application Loop
; -----------------------------------------------------------------------------
; This is the main loop of the program. It currently waits for user input
; and checks if the 'Q' key is pressed to quit.
app_loop:

    jsr select_player  ; Call the player selection routine.

getinput:
    jsr GETIN          ; Wait for and get a character from the keyboard buffer.
menu_quit:
    cmp #'Q'           ; Compare the input character with 'Q'.
    beq quit           ; If it's 'Q', branch to the quit routine.
done:
    jmp app_loop       ; If not 'Q', loop back to wait for more input.

; -----------------------------------------------------------------------------
; Termination Routine
; -----------------------------------------------------------------------------
quit:
    br_screen_clear    ; Clear the entire screen.
    br_screen_set_mode SCREEN_MODE_80X60 ; Restore the default text mode.
    br_text_print quit_string ; Display a "thanks for playing" message.
    sec                ; Set the carry flag before returning to BASIC.
    jsr enter_basic    ; Exit the program and return to the BASIC ready prompt.

; -----------------------------------------------------------------------------
; Data
; -----------------------------------------------------------------------------
welcome_string:            .asciiz "loading pac-man"
quit_string:               .asciiz "thanks for playing pac-man"