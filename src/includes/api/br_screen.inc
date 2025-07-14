;-------------------------------------------------------------------
; Name: br_screen_clear
;-------------------------------------------------------------------
; Description: Clears the screen 
;
; Note: 
; URL:
;-------------------------------------------------------------------
; Inputs: None
; Returns: None
; Destroys: lda
;-------------------------------------------------------------------
        .macro br_screen_clear
                pha
                lda #$93
                jsr CHROUT
                pla
        .endmacro

;-------------------------------------------------------------------
; Name: br_screen_set_mode
;-------------------------------------------------------------------
; Description: Sets the screen to the given mode 
;
; Note: 
; URL:
;-------------------------------------------------------------------
; Inputs: mode, the scren mode to set
; Returns: None
; Destroys: lda
;-------------------------------------------------------------------
        .macro br_screen_set_mode mode
                lda #<mode
                clc
                jsr SCREEN_MODE
        .endmacro