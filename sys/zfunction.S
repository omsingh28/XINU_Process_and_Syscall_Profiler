	.file	"zfunction.c"
	.text
	.p2align 4
	.globl	zfunction
	.type	zfunction, @function
zfunction:
.LFB23:
	.cfi_startproc
	movl	4(%esp), %eax
	sall	$8, %eax
	andl	$-1044736, %eax
	orb	$-1, %al
	ret
	.cfi_endproc
.LFE23:
	.size	zfunction, .-zfunction
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
