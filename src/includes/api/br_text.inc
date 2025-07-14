;-------------------------------------------------------------------
; Equates
;-------------------------------------------------------------------
ASCII_CR                   = $0D   ; ASCII/PETSCII code for carraige return
ASCII_ZERO                 = $30   ; ASCII/PETSCII code for zero
SETTXT                     = $FFD3 ; Set text cursor position (A=X, Y=Y)

;-------------------------------------------------------------------
; Name: br_text_print
;-------------------------------------------------------------------
; Description: Prints a null terminated string to the console, 
;              followed by a newline
; Note: 
; URL:
;-------------------------------------------------------------------
; Inputs: string, location of string in memory
; Returns: None
; Destroys: lda, ldy
;-------------------------------------------------------------------

        .macro  br_text_print str
            pha
            lda #<str
            sta ASCII_ZERO
            lda #>str
            sta ASCII_ZERO+1
            phy
            ldy #0
        @printchr:
            lda (ASCII_ZERO),y
            beq @done
            jsr CHROUT
            iny
            bra @printchr
        @done:
            ply
            lda #ASCII_CR
            jsr CHROUT
            pla
        .endmacro

;-------------------------------------------------------------------
; Name: br_text_print_at
;-------------------------------------------------------------------
; Description: Prints a null terminated string to the console, 
;              followed by a newline at a specific position
;              (x_pos, y_pos) on the screen.
; Note: 
; URL:
;-------------------------------------------------------------------
; Inputs: string, location of string in memory
;         x_pos, x coordinate (0-79 for 80-column screen)
;         y_pos, y coordinate (0-29 for 30-row screen)
; Returns: None
; Destroys: lda, ldy
;-------------------------------------------------------------------
        .macro  br_text_print_at str, x_pos, y_pos
            pha             ; Save A register
            phy             ; Save Y register

            ; Set cursor position using SETTXT
            ; TODO: Move curser to (x_pos, y_pos)
            lda #x_pos      ; Load X position into 
        

            ; Now, proceed with the string printing logic, similar to br_text_print
            lda #<str       ; Load low byte of string address
            sta ASCII_ZERO  ; Store in Zero Page (ZP) temporary
            lda #>str       ; Load high byte of string address
            sta ASCII_ZERO+1 ; Store in ZP temporary

            ldy #0          ; Reset Y for string indexing (string length counter)
        @printchr_at:
            lda (ASCII_ZERO),y ; Load character from string
            beq @done_at    ; If null terminator (0), finished
            jsr CHROUT      ; Print character using ROM routine
            iny             ; Increment string index
            bra @printchr_at ; Loop for next character
        @done_at:
            lda #ASCII_CR   ; Print carriage return (newline)
            jsr CHROUT      ; This moves the cursor to the start of the next line,
                            ; which is typical for text output and might be useful
                            ; if you're printing multiple menu items.
            
            ply             ; Restore Y register
            pla             ; Restore A register
        .endmacro