//D13.2.137 of ARMv8 reference manual
.globl irq_init_vectors
irq_init_vectors:
    adr x0, vectors
    msr vbar_el1, x0
    ret
//C5.2.2 of ARMv8 reference manual
.globl irq_enable
irq_enable:
    msr daifclr, #2
    ret

.globl irq_disable
irq_disable:
    msr daifset, #2
    ret

.globl irq_barrier
irq_barrier:
    dsb sy
    ret
