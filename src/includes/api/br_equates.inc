;-------------------------------------------------------------------
; Kernal Routines
;-------------------------------------------------------------------
;
;-------------------------------------------------------------------

CHROUT                          = $FFD2
CHRIN                           = $FFCF
SCREEN_MODE                     = $FF5F
MOUSE_CONFIG                    = $FF68
MOUSE_GET                       = $FF6B
GETIN                           = $FFE4

;-------------------------------------------------------------------
; Graphics
;-------------------------------------------------------------------
;
;-------------------------------------------------------------------

GRAPH_init          = $FF20
GRAPH_clear         = $FF23
GRAPH_set_window    = $FF26
GRAPH_set_colors    = $FF29
GRAPH_draw_line     = $FF2C
GRAPH_draw_rect     = $FF2F
GRAPH_move_rect     = $FF32
GRAPH_draw_oval     = $FF35
GRAPH_draw_image    = $FF38
GRAPH_set_font      = $FF3B
GRAPH_get_char_size = $FF3E
GRAPH_put_char      = $FF41
enter_basic         = $FF47


;-------------------------------------------------------------------
; QoL
;-------------------------------------------------------------------
;
;-------------------------------------------------------------------

TRUE                            = $1
FALSE                           = $0

;-------------------------------------------------------------------
; Screen Mode Constants
;-------------------------------------------------------------------
; These constants define various screen modes for the Commander X16.
; They can be used with a KERNAL routine (e.g., SYS $FFxx or a POKE)
; to change the display mode.
;-------------------------------------------------------------------

SCREEN_MODE_80X60              = $00
SCREEN_MODE_80X30              = $01
SCREEN_MODE_40X60              = $02
SCREEN_MODE_40X30              = $03
SCREEN_MODE_40X15              = $04
SCREEN_MODE_20X30              = $05
SCREEN_MODE_20X15              = $06
SCREEN_MODE_22X23              = $07
SCREEN_MODE_64X50              = $08
SCREEN_MODE_64X25              = $09
SCREEN_MODE_32X50              = $0A
SCREEN_MODE_32X25              = $0B
SCREEN_MODE_320X240_256C       = $80

; RAM Addresses

; Kernal Registers
r0					= $02
r0L					= r0
r0H					= r0+1
r1					= $04
r1L					= r1
r1H					= r1+1
r2					= $06
r2L					= r2
r2H					= r2+1
r3					= $08
r3L					= r3
r3H					= r3+1
r4					= $0A
r4L					= r4
r4H					= r4+1
r5					= $0C
r5L					= r5
r5H					= r5+1
r6					= $0E
r6L					= r6
r6H					= r6+1
r7					= $10
r7L					= r7
r7H					= r7+1
r8					= $12
r8L					= r8
r8H					= r8+1
r9					= $14
r9L					= r9
r9H					= r9+1
r10					= $16
r10L				= r10
r10H				= r10+1
r11					= $18
r11L				= r11
r11H				= r11+1
r12					= $1A
r12L				= r12
r12H				= r12+1
r13					= $1C
r13L				= r13
r13H				= r13+1
r14					= $1E
r14L				= r14
r14H				= r14+1
r15					= $20
r15L				= r15
r15H				= r15+1