import sys
    

def main():
    t = int(sys.stdin.readline())
    for i in range(t):
    
        n = int(sys.stdin.readline())
        l = list(map(int, sys.stdin.readline().strip().split(' ')))
           
        l[::2] = sorted(l[::2])
        l[1::2] = sorted(l[1::2])
        
        for j in range(len(l)-1):
            if l[j] > l[j+1]:
                o = j
                break
        else:
            o = 'OK'
        
        print('Case #{}: {}'.format(i+1, o))


if __name__ == "__main__":
    main()
