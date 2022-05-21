#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int n, m;
bool mark[10][10], vis[4][10];

bool valid()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mark[i][j] && !vis[0][i] && !vis[1][j] && !vis[2][i + j] && !vis[3][n + j - i])
                return false;
    return true;
}

bool dfs(int cur, int d, int res)
{
    if (d == res)
    {
        if (valid())
            return true;
        return false;
    }
    for (int i = cur; i < n * m; i++)
    {
        int r = i / m, l = i % m;
        int t1 = vis[0][r], t2 = vis[1][l], t3 = vis[2][r + l], t4 = vis[3][n + l - r];
        vis[0][r] = vis[1][l] = vis[2][r + l] = vis[3][n + l - r] = true;
        if (dfs(i, d + 1, res))
            return true;
        vis[0][r] = t1, vis[1][l] = t2, vis[2][r + l] = t3, vis[3][n + l - r] = t4;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 0;
    while (1)
    {
        cin >> n;
        if (!n)
            break;
        cin >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                char x;
                cin >> x;
                mark[i][j] = x == 'X';
            }
        for (int res = 0;; res++)
        {
            memset(vis, 0, sizeof(vis));
            if (dfs(0, 0, res))
            {
                if (t++)
                    cout << endl;
                cout << "Case " << t << ": " << res;
                break;
            }
        }
    }
}