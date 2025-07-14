;
; Title:        Bitroit.dev
;
; Description:  Simple splash screen for Bitriot.dev
; Author:		Andy McCall, andy@bitriot.dev, others welcome!
;
; Created:		2024-11-25 @ 17:28
; Last Updated:	2024-11-25 @ 17:28
;
; Modinfo:

.segment "STARTUP"
.segment "INIT"
.segment "ONCE"

.segment "CODE"

   jmp start

; API includes
   .include "includes/api/br_equates.inc"
   .include "includes/api/br_text.inc"
   .include "includes/api/br_screen.inc"
   .include "includes/api/br_mouse.inc"

; App includes

start:

    br_text_print welcome_string

    br_mouse_hide

    jsr GRAPH_init

    br_screen_set_mode SCREEN_MODE_320X240_256C

    lda #$00             ; Stroke
    ldx #$00             ; Fill
    ldy #$00             ; background
    jsr GRAPH_set_colors
   
    jsr GRAPH_clear

;--------------------------------------------------------------

app_loop:

getinput:
    jsr GETIN
menu_quit:
    cmp #'Q'
    beq quit
done:
    jmp app_loop

quit:
    br_screen_clear
    br_screen_set_mode SCREEN_MODE_80X60
    br_text_print quit_string
    sec
    jsr enter_basic    ; enter BASIC sec for cold restart.

;-----------------------------------------------------------

welcome_string:            .asciiz "loading pac-man"
quit_string:               .asciiz "thanks for playing pac-man"