#include <iostream>
#include <set>
#define endl '\n'

using namespace std;

int x[8], n = 8;
bool col[8] = {}, diag[15] = {}, rdiag[15] = {};
set<int> skip;

void dfs(int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << (j != x[i] ? '.' : 'Q');
            cout << endl;
        }
        return;
    }
    if (skip.count(cur))
    {
        dfs(cur + 1);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !diag[i + cur] && !rdiag[i - cur + n])
        {
            x[cur] = i;
            col[i] = diag[i + cur] = rdiag[i - cur + n] = true;
            dfs(cur + 1);
            col[i] = diag[i + cur] = rdiag[i - cur + n] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, r, c;
    cin >> k;
    while (k--)
    {
        cin >> r >> c;
        x[r] = c;
        skip.insert(r);
        col[c] = diag[c + r] = rdiag[c - r + n] = true;
    }
    dfs(0);
}