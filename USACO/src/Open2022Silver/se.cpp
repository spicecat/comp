#include <iostream>
#include <string>
#include <set>
#define endl '\n'
using namespace std;
using lli = long long int;
using str = string;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

str s, t;
int freqs[18] = {}, freqt[18] = {};
set<char> q;

bool check()
{
    int len = 0;
    for (char c : q)
    {
        if (freqs[c - 97] != freqt[c - 97])
            return false;
        len += freqs[c - 97];
    }
    int ps = 0, pt = 0;
    while (len--)
    {
        while (!q.count(s[ps]))
            ps++;
        while (!q.count(t[pt]))
            pt++;
        if (s[ps] != t[pt])
            return false;
        ps++;
        pt++;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    for (char c : s)
        freqs[c - 97]++;
    for (char c : t)
        freqt[c - 97]++;
    lli Q;
    cin >> Q;
    while (Q--)
    {
        str qq;
        cin >> qq;
        q.clear();
        for (char c : qq)
            q.insert(c);
        cout << (check() ? 'Y' : 'N');
    }
}