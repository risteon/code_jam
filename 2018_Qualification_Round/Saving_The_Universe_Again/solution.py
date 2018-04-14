import sys


def damage(prog):
    d = 1
    s = 0
    for c in prog:
        if c is 'C':
            d *= 2
        elif c is 'S':
            s += d
        else:
            raise RuntimeError('Invalid Input {}'.format(prog))
    return s

    
def hack(prog):
    k = prog.rfind('CS')
    return prog[:k] + 'SC' + prog[k+2:]
    

def main():
    t = int(sys.stdin.readline())
    for i in range(t):
    
        d, prog = map(str.strip, sys.stdin.readline().split(' '))
        d = int(d)
        
        min = prog.count('S')
        if min > d:
            output = 'IMPOSSIBLE'
        else:
            h = 0
            c = damage(prog)
            while c > d:
                prog = hack(prog)
                c = damage(prog)
                h += 1
            output = str(h)
        
        print('Case #{}: {}'.format(i+1, output))


if __name__ == "__main__":
    main()
