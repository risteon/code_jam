#!/usr/bin/env python3
import sys

def get_guess(a, b):
    return ((b - a + 1)//2) + a


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        a, b = map(int, sys.stdin.readline().split(' '))
        n = int(sys.stdin.readline())

        for _ in range(n):
            q = get_guess(a, b)
            print(q)
            sys.stdout.flush()
            answer = sys.stdin.readline().strip()
            if answer == 'CORRECT':
                break
            elif answer == 'TOO_SMALL':
                a, b = q, b
            elif answer == 'TOO_BIG':
                a, b = a, q-1
            else:
                exit(1)
        else:
            exit(2)


if __name__ == "__main__":
    main()

