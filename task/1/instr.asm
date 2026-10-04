# Write max = 0 -> R3
READ 0
WRITE R3

# Write startx = 1 -> R1
READ 1
WRITE R1

# Write i startx + 1 -> R2
ADD 1
WRITE R2

# Write size = [startx] + i -> R4
ADD [R1]
WRITE R4

WHILE_START:
# if (max - mem[i] > 0) goto skip;
READ R3
CMP [R2]
JCP SKIP

# max = mem[i];
READ [R2]
WRITE R3

SKIP:

# i += 1
READ R2
ADD 1
WRITE R2

# if (size - i > 0) goto while_start;
READ R4
CMP R2
JCP WHILE_START

# mem[size] = max
READ R3
WRITE [R4]

END:
JMP END
