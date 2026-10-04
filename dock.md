```
R0 - accum
R[1-7] - registers
```

```
READ val: R0 <- val
WRITE val: R0 -> val

ADD val: R0 <- R0 + val
SUB val: R0 <- R0 - val
MUL val: R0 <- R0 * val
DIV val: R0 <- R0 / val

CMP val: R0 <- (val - R0 >= 0? val - R0: 0)

JMP val: jumps to the instruction val
JCP val: jump to the instruction val if (R0 > 0)
```

---

Register is 3 bit wide
Command is 4 bit wide

Val could be register, number, memory unit referencing register, memory unit referencing by number

```
Instruction structure:

[COMMAND] [VALUE TYPE] [        VALUE       ]
[  xxxx ] [    xx    ] [ x(sizeof(RAW) - 6) ]
```



