;-------------------------------------------------------------------
; Name: br_mouse_show
;-------------------------------------------------------------------
; Description: Show the mouse pointer 
;
; Note: Calls the macro br_mouse_show
; URL:
;-------------------------------------------------------------------
; Inputs: None
; Returns: None
; Destroys: lda
;-------------------------------------------------------------------
        .macro br_mouse_show
            br_mouse_config TRUE
        .endmacro

;-------------------------------------------------------------------
; Name: br_hide_mouse
;-------------------------------------------------------------------
; Description: Hides the mouse pointer 
;
; Note: Calls the macro br_mouse_config
; URL:
;-------------------------------------------------------------------
; Inputs: None
; Returns: None
; Destroys: lda
;-------------------------------------------------------------------
        .macro br_mouse_hide
            br_mouse_config FALSE
        .endmacro

;-------------------------------------------------------------------
; Name: br_mouse_config
;-------------------------------------------------------------------
; Description: Shows or hides the mouse pointer 
;
; Note: Called by br_mouse_show, br_mouse_hide
; URL:
;-------------------------------------------------------------------
; Inputs: bool, 1 to show the mouse, 0 to hide it
; Returns: None
; Destroys: lda
;-------------------------------------------------------------------
        .macro br_mouse_config bool
            lda #<bool
            jsr MOUSE_CONFIG
        .endmacro