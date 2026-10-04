# Set up R1 <- A
READ 1
WRITE R1

# Set up R2 <- B
READ 7
WRITE R2

# int *i = a -> R3;
READ R1
WRITE R3

# R2 <- (B-A)
READ R2
SUB R3
WRITE R2

# int ans = 0;
READ 0
WRITE R4

WHILE_START:

# *(i + b - a)
READ R3
ADD R2
READ [R0]
# * (*i)
MUL [R3]
# ans += (*i) * (* (i + b - a));
ADD R4
WRITE R4

# i += 1
READ R3
ADD 1
WRITE R3

# if (a + 6 - i) > 0) goto while_start
READ R1
ADD 6
CMP R3
JCP WHILE_START

# *(b - a + 6) = ans;
READ R1
ADD R2
ADD 6
WRITE R5
READ R4
WRITE [R5]

DONE:
JMP DONE
