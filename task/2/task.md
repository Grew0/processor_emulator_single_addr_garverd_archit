## Task 2
### Task
Сверстка двух массивов, 6 элементов, целые числа без знака
### Mem layout
```
memory = [A[0] A[1] .. A[5] .. B[0] B[1] .. B[5]        ans ]
     A ---^               B ---^   slot to write ans ---^
```
R1 <- A
R2 <- B
### Iteration 1
```C++
int i = 0;
int ans = 0;
while(i<6){
    ans += A[i] * B[i];
    i += 1;
}
B[6] = ans;
```
### Iteration 2
```C++
int *i = a;
int ans = 0;
do {
    ans = (*i) * (*(i + b - a));
    i += 1;
} while (6 - (i - a) > 0);
*(b - a + 6) = ans;
```
### Iteration 3
```C++
int *i = a;
int ans = 0;
while_start:
    ans += (*i) * (* (i + b - a));
    if (a + 6 - i) > 0) goto while_start
}
*(b - a + 6 + a) = ans;
```
### Registers

| R | var   |   | R | var   |
|---|-------| - |---|-------|
| 0 | accum |   | 0 | accum |
| 1 | A     |   | 1 | A     |
| 2 | B     |   | 2 | B - A |
                | 3 | I     |
                | 4 | ans   |

```ASM
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
```
