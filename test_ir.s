  .text
  .global half
half:
  addi sp, sp, -256
entry:
  li a0, 0
  addi sp, sp, 256
  ret
  .global main
main:
  addi sp, sp, -256
entry:
  call half
  li t0, 0
  add t0, t0, sp
  sw a0, (t0)
  lw t0, 0(sp)
  mv a0, t0
  addi sp, sp, 256
  ret
