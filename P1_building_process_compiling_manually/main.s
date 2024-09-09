	.cpu cortex-m4
	.arch armv7e-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	bl	led_init
	bl	timebase_init
	bl	usart_tx_init
	bl	usart_enabled
.L4:
	movs	r3, #0
	str	r3, [r7, #4]
	ldr	r3, [r7, #4]
	cmp	r3, #0
	bne	.L2
	bl	motor_main
	b	.L4
.L2:
	bl	valve_main
	b	.L4
	.size	main, .-main
	.section	.rodata
	.align	2
.LC0:
	.ascii	"Motor is running\000"
	.text
	.align	1
	.global	motor_run
	.syntax unified
	.thumb
	.thumb_func
	.type	motor_run, %function
motor_run:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r0, .L6
	bl	printf
	nop
	pop	{r7, pc}
.L7:
	.align	2
.L6:
	.word	.LC0
	.size	motor_run, .-motor_run
	.section	.rodata
	.align	2
.LC1:
	.ascii	"Motor is stop\000"
	.text
	.align	1
	.global	motor_stop
	.syntax unified
	.thumb
	.thumb_func
	.type	motor_stop, %function
motor_stop:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r0, .L9
	bl	printf
	nop
	pop	{r7, pc}
.L10:
	.align	2
.L9:
	.word	.LC1
	.size	motor_stop, .-motor_stop
	.section	.rodata
	.align	2
.LC2:
	.ascii	"The valve is close\000"
	.text
	.align	1
	.global	valve_close
	.syntax unified
	.thumb
	.thumb_func
	.type	valve_close, %function
valve_close:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r0, .L12
	bl	printf
	nop
	pop	{r7, pc}
.L13:
	.align	2
.L12:
	.word	.LC2
	.size	valve_close, .-valve_close
	.section	.rodata
	.align	2
.LC3:
	.ascii	"The valve is open\000"
	.text
	.align	1
	.global	valve_open
	.syntax unified
	.thumb
	.thumb_func
	.type	valve_open, %function
valve_open:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r0, .L15
	bl	printf
	nop
	pop	{r7, pc}
.L16:
	.align	2
.L15:
	.word	.LC3
	.size	valve_open, .-valve_open
	.align	1
	.global	motor_main
	.syntax unified
	.thumb
	.thumb_func
	.type	motor_main, %function
motor_main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
.L18:
	bl	motor_run
	movs	r0, #1
	bl	delay
	bl	motor_stop
	movs	r0, #1
	bl	delay
	b	.L18
	.size	motor_main, .-motor_main
	.align	1
	.global	valve_main
	.syntax unified
	.thumb
	.thumb_func
	.type	valve_main, %function
valve_main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
.L20:
	bl	valve_open
	movs	r0, #1
	bl	delay
	bl	valve_close
	movs	r0, #1
	bl	delay
	b	.L20
	.size	valve_main, .-valve_main
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
