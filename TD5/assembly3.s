movq $0x3765656461363732, %r9
movq $0x55619000, %rdi
movq %r9, (%rdi)
movq $0x0, 0x8(%rdi)
retq
