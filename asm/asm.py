#!/bin/python
import sys


labels = dict()

def parse_val(val) -> tuple:
    isMem = False
    isReg = False
    value = 0
    val = val.strip()
    if val in labels:
        return (isMem, isReg, labels[val])
    if val[0] == '[':
        if val[-1] == ']':
            val = val[1:-1]
            isMem = True
        else:
            return (-1,)
    if val[0] == 'R':
        if val[1:].isdigit():
            isReg = True
            value = int(val[1:])
        else:
            return (-1,)
    else:
        if val.isdigit():
            value = int(val)
        else:
            return (-1,)
    return (isMem, isReg, value)

def parse_command(comm):
    d = {
        "READ": 0x0,
        "WRITE": 0x1,
        "ADD": 0x2,
        "SUB": 0x3,
        "MUL": 0x4,
        "DIV": 0x5,
        "CMP": 0x6,
        "JMP": 0x7,
        "JCP": 0x8,
    }
    if (comm in d):
        return d[comm]
    return -1


def precompileLabels(lines):
    out = []
    ir = 0
    for i in lines:
        line = i.strip()
        if len(i) == 0 or i[0] == "#":
            continue
        if i[-1] == ":" :
            if " " not in i and ":" not in i[:-1]:
                if i[:-1] in labels:
                    print("Repeating label: ", i)
                    return
                else:
                    labels[i[:-1]] = ir
                    continue
            else:
                print("FUN label: ", i)
                return
        out += [(ir, line)]
        ir += 1
    return out

def precompileCommands(lines):
    out = []
    for i in lines:
        tmp = i[1].split()
        if len(tmp) != 2:
            print("FUN Command: ", i)
            return
        comm, val = tmp
        out += [(i[0], comm, val)]
    return out

def commands_to_numbers(lines):
    out = []
    for line in lines:
        ir, comm_str, val_str = line
        parsedCommand = parse_command(comm_str)
        parsedValue = parse_val(val_str)

        if parsedCommand == -1:
            print("FUN COMM:", comm_str, " line: ", line)
        if parsedValue[0] == -1:
            print("FUN VAL:", val_str, " line: ", line)
        print(ir, parsedCommand, parsedValue)

        ### 4 / 2 / 26
        print( (parsedCommand<<28) | ( (int(parsedValue[0])*2 + int(not parsedValue[1])) <<26) | parsedValue[2])
        out += [ (parsedCommand<<28) | ( (int(parsedValue[0])*2 + int(not parsedValue[1])) <<26) | parsedValue[2]]
    return out


def main():
    if len(sys.argv) != 3:
        print("Usage asm.py file.asm file.bin")
        return
    pass
    lines = open(sys.argv[1]).read().split('\n')
    lines = precompileLabels(lines)
    lines = precompileCommands(lines)
    out = commands_to_numbers(lines)
    open(sys.argv[2], mode="w").write("\n".join(map(str, out)))


if __name__ == "__main__":
    main()
