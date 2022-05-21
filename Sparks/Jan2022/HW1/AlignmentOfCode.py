lines, lens = [], []
while True:
    line = input().strip()
    if(line):
        words = list(filter(None, line.split(' ')))
        lines.append(words)
        lens.append(list(map(len, words)))
    else:
        break
cols = max(map(len, lens))

for i in range(cols):
    maxLen = max([len(line[i]) if i < len(line) else 0 for line in lines])
    for line in lines:
        if i < len(line):
            line[i] += ' '*(maxLen-len(line[i])+1)
print('\n'.join(''.join(line) for line in lines))
