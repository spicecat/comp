#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define f first
#define s second
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
using vii = vector<pii>;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

int N;
pii va[100000];
bool vis[100000] = {};
vii loop;
lli res = 0;

void recur(int c)
{
    if (vis[c])
    {
        auto it = find(ALL(loop), va[c]);
        if (it != loop.end())
            res -= (*min_element(it, loop.end())).f;
        return;
    }
    loop.pb(va[c]);
    vis[c] = true;
    res += va[c].f;
    recur(va[c].s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int aa, vv;
        cin >> aa >> vv;
        va[i] = {vv, aa - 1};
    }
    for (int i = 0; i < N; i++)
    {
        loop.clear();
        recur(i);
    }
    cout << res;
}