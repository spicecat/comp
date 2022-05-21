while(True):
    N = int(input())
    if(N == 0):
        break
    cards = list(range(1, N+1))
    discarded = []
    while len(cards) > 1:
        discarded.append(cards.pop(0))
        cards.append(cards.pop(0))
    print('Discarded cards:', ', '.join(map(str, discarded)))
    print('Remaining card:', cards[0])
