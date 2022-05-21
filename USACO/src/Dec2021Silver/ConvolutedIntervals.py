N, M = map(int, input().split(' '))
I = []
for i in range(N):
    I.append(tuple(map(int, input().split(' '))))
I.sort()
print(I)
c = [0, 0, 1, 3, 4, 4, 4, 3, 3, 1, 1]
for k in range(2*M+1):
    for i in range(N):
        if 2*I[i][0] > k:
            break
        for j in range(i, N):
            if I[i][0]+I[j][0] > k:
                break
            print(k, i, j, I[i][0], I[j][0])
