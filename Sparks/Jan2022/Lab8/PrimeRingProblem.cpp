#include <iostream>
#include <set>
#define endl '\n'

using namespace std;

int n, x[17] = {};
bool used[17] = {};
bool isprime(int n)
{
    set<int> s = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    return s.count(n) == 1;
}
void dfs(int cur)
{
    if (cur == n)
    {
        if (!isprime(x[cur - 1] + x[0]))
            return;
        cout << x[0];
        for (int i = 1; i < n; i++)
            cout << ' ' << x[i];
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i] && isprime(x[cur - 1] + i))
        {
            x[cur] = i;
            used[i] = true;
            dfs(cur + 1);
            used[i] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (cin >> n)
    {
        if (t != 1)
            cout << endl;
        x[0] = 1;
        used[1] = true;
        cout << "Case " << t++ << ":\n";
        dfs(1);
    }
}