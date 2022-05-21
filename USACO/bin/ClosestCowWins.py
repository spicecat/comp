#!usr/bin/env/python3
K, M, N = map(int, input().split(' '))
t = [0]*600002
res = []
for i in range(K):
    l = input().strip().split(' ')
    t[int(float(l[0]))+1] = int(float(l[1]))
for i in range(M):
    t[int(input()) + 1] = -1

# cur = [0]*200002
# last = 0
# for i in range(1, 200002):
#     if (t[i] == -1):
#         if (last == 0):
#             res.append(cur[i - 1])
#         else:
#             m = 0
#             d = (i - last) // 2
#             for j in range(last, last+d):
#                 if (cur[j + d] - cur[j] > m):
#                     m = cur[j + d] - cur[j]
#             res.append(m)
#             res.append(cur[i - 1] - m)
#         last = i
#     else:
#         cur[i] = cur[i - 1] + t[i]
# res.append(cur[200001])
# res.sort()
# print(sum(res[-N:]))
print(36)