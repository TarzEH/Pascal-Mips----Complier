.data
a: .space 8
b: .space 8
d: .space 200


strBuff: .space 200
.text
main:

li $v0,6
syscall
s.s $f0, a
li $v0,6
syscall
s.s $f0, b
l.s $f0, b
li $v0,2
mov.s $f12,$f0
 syscall

