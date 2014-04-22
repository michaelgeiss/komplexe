	.text
	.globl calc_expr
calc_expr:
	movl	4(%esp), %edi
	movl	$25, %eax
	pushl	%eax
	movl	$7, %eax
	pushl	%eax
	movl	%edi, %eax
	popl	%ebx
	addl	%ebx, %eax
	popl	%ebx
	cmp	%eax, %ebx
	jg	larger
	jl	smaller
	larger:
	movl	%ebx, %eax
	smaller:
	retl
