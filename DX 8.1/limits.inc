;/***
;*limits.h - implementation dependent values
;*
;*       Copyright (c) 1985-2000, Microsoft Corporation.  All rights reserved.
;*
;*Purpose:
;*       Contains defines for a number of implementation dependent values
;*       which are commonly used in C programs.
;*       [ANSI]
;*
;*       [Public]
;*
;****/

;#if     _MSC_VER > 1000
;#pragma once
;#endif

IFNDEF _INC_LIMITS
_INC_LIMITS=1


    CHAR_BIT            EQU         8                   ;/* number of bits in a char */
    SCHAR_MIN           EQU         (-128)              ;/* minimum signed char value */
    SCHAR_MAX           EQU         127                 ;/* maximum signed char value */
    UCHAR_MAX           EQU         0xff                ;/* maximum unsigned char value */

    IFNDEF _CHAR_UNSIGNED
        CHAR_MIN            EQU         SCHAR_MIN       ;/* mimimum char value */
        CHAR_MAX            EQU         SCHAR_MAX       ;/* maximum char value */
    ELSE
        CHAR_MIN            EQU         0
        CHAR_MAX            EQU         UCHAR_MAX
    ENDIF                                           ;/* _CHAR_UNSIGNED */

    MB_LEN_MAX          EQU         5                   ;/* max. # bytes in multibyte char */
    SHRT_MIN            EQU         (-32768)            ;/* minimum (signed) short value */
    SHRT_MAX            EQU         32767               ;/* maximum (signed) short value */
    USHRT_MAX           EQU         0ffffh              ;/* maximum unsigned short value */
    INT_MIN             EQU         (-2147483647 - 1)   ;/* minimum (signed) int value */
    INT_MAX             EQU         2147483647          ;/* maximum (signed) int value */
    UINT_MAX            EQU         0ffffffffh          ;/* maximum unsigned int value */
    LONG_MIN            EQU         (-2147483647L - 1)  ;/* minimum (signed) long value */
    LONG_MAX            EQU         2147483647L         ;/* maximum (signed) long value */
    ULONG_MAX           EQU         0ffffffffh        ;/* maximum unsigned long value */

IFDEF _INTEGRAL_MAX_BITS
    IF     _INTEGRAL_MAX_BITS GE 8
        _I8_MIN             EQU         (-127i8 - 1)        ;/* minimum signed 8 bit value */
        _I8_MAX             EQU         127i8               ;/* maximum signed 8 bit value */
        _UI8_MAX            EQU         0xffui8             ;/* maximum unsigned 8 bit value */
    ENDIF

    IF     _INTEGRAL_MAX_BITS GE 16
        _I16_MIN            EQU         (-32767i16 - 1)     ;/* minimum signed 16 bit value */
        _I16_MAX            EQU         32767i16            ;/* maximum signed 16 bit value */
        _UI16_MAX           EQU         0xffffui16          ;/* maximum unsigned 16 bit value */
    ENDIF

    IF     _INTEGRAL_MAX_BITS GE 32
        _I32_MIN            EQU         (-2147483647i32 - 1) ;/* minimum signed 32 bit value */
        _I32_MAX            EQU         2147483647i32       ;/* maximum signed 32 bit value */
        _UI32_MAX           EQU         0xffffffffui32      ;/* maximum unsigned 32 bit value */
    ENDIF

    IF     _INTEGRAL_MAX_BITS GE 64
;/* minimum signed 64 bit value */
        _I64_MIN            EQU         (-9223372036854775807i64 - 1)
;/* maximum signed 64 bit value */
        _I64_MAX            EQU         9223372036854775807i64
;/* maximum unsigned 64 bit value */
        _UI64_MAX           EQU         0xffffffffffffffffui64
    ENDIF

    IF     _INTEGRAL_MAX_BITS GE 128
;/* minimum signed 128 bit value */
        _I128_MIN           EQU         (-170141183460469231731687303715884105727i128 - 1)
;/* maximum signed 128 bit value */
        _I128_MAX           EQU         170141183460469231731687303715884105727i128
;/* maximum unsigned 128 bit value */
        _UI128_MAX          EQU         0xffffffffffffffffffffffffffffffffui128
    ENDIF

ENDIF

    IFDEF  _POSIX_

        _POSIX_ARG_MAX      EQU         4096
        _POSIX_CHILD_MAX    EQU         6
        _POSIX_LINK_MAX     EQU         8
        _POSIX_MAX_CANON    EQU         255
        _POSIX_MAX_INPUT    EQU         255
        _POSIX_NAME_MAX     EQU         14
        _POSIX_NGROUPS_MAX  EQU         0
        _POSIX_OPEN_MAX     EQU         16
        _POSIX_PATH_MAX     EQU         255
        _POSIX_PIPE_BUF     EQU         512
        _POSIX_SSIZE_MAX    EQU         32767
        _POSIX_STREAM_MAX   EQU         8
        _POSIX_TZNAME_MAX   EQU         3

        ARG_MAX             EQU         14500      ; /* 16k heap, minus overhead */
        LINK_MAX            EQU         1024
        MAX_CANON           EQU         _POSIX_MAX_CANON
        MAX_INPUT           EQU         _POSIX_MAX_INPUT
        NAME_MAX            EQU         255
        NGROUPS_MAX         EQU         16
        OPEN_MAX            EQU         32
        PATH_MAX            EQU         512
        PIPE_BUF            EQU         _POSIX_PIPE_BUF
        SSIZE_MAX           EQU         _POSIX_SSIZE_MAX
        STREAM_MAX          EQU         20
        TZNAME_MAX          EQU         10

    ENDIF   ;  /* POSIX */

ENDIF   ;  /* _INC_LIMITS */
