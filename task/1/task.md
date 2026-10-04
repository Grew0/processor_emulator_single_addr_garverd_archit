## Task 1
### Task
Поиск максимума в массиве
### Mem layout
```
memory = [arr_size arr[0] arr[1] ... ]
startx ---^
```
### Iteration 1
``` C++
int i = 0;
int size = mem[startx];
int max = 0;
while (i < size){
    if (mem[startx + i + 1] > max){
        max = mem[startx + i + 1]
    }
}
```




### Iteration 2
``` C++
int i = startx + 1;
int size = mem[startx] + i;
int max = 0;
do{
    if (mem[i] > max){
        max = mem[i]
    }
}while (i < size);
mem[size] = max;
```

### Iteration 3 (only goto and if ( > 0) )
``` Pseudo C++
int i = startx + 1;
int size = mem[startx] + i;
int max = 0;

while_start:
if (max - mem[i] > 0) goto skip;
max = mem[i];
skip:
i += 1
if (size - i > 0) goto while_start;

mem[size] = max

end:
goto end;
```



| R | var    |
|---|--------|
| 0 | accum  |
| 1 | startx |
| 2 | i      |
| 3 | max    |
| 4 | size   |


```ASM
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
```
