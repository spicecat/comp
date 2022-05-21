#include <iostream>
#include <vector>
#define pb push_back
#define endl '\n'
#define pii pair<int, int>
#define vii vector<pii>
#define first f
#define second s

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    while (cin >> k)
    {
        vii res;
        cout << k;
        for (int y = k + 1; y <= 2 * k; y++)
            if (y * k * (y - k) == 0)
            {
                int x = y * k / (y - k);
                res.pb({x, y});
            }
        for (pii p : res)
            cout << "1/" << k << "  = 1/" << p.f << " + 1/" << p.s << endl;
    }
}