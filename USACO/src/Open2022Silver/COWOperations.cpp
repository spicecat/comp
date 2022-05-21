#include <iostream>
#include <string>
using namespace std;
using str = string;

#pragma GCC optimize("Ofast")

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l, r, s[200001];
    str ss;
    cin >> ss;
    int i = 1;
    for (char c : ss)
    {
        s[i] = s[i - 1] ^ (1 + (c == 'O') + 2 * (c == 'W'));
        i++;
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        cin >> l >> r;
        cout << ((s[r] ^ s[l - 1]) == 1 ? 'Y' : 'N');
    }
}