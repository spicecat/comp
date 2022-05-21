l = int(input())
for i in range(l):
    D, I = map(int, input().split())
    print(int('1'+str(bin(I-1))[2:].zfill(D-1)[::-1], 2))
