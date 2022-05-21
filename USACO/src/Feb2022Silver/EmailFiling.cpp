#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define endl '\n'
#define lli long long int
#define vi vector<int>

using namespace std;

void print(vi v)
{
    for (int c : v)
        cout << c << ',';
    cout << '\n';
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int M, N, K;
        cin >> M >> N >> K;
        vi v(N);
        for (int i = 0; i < N; i++)
            cin >> v[i];
        int F = 0;
        vi::iterator E = v.begin();
        while (!v.empty())
        {
            E = min_element(E, v.end());
            // cout << 'm' << *E << ';';
            if (*E >= F)
                F = *E - K + 1;
            else
                break;
            E = max(v.begin(), E - K + 1);
            // cout << *E << ';' << F;
            // print(v);
            for (vi::iterator e = E; e < min(E + K, v.end());)
            {
                if (*e >= F && *e < min(F + K, M + 1))
                {
                    if (e + K >= v.end())
                    {
                        v.erase(e);
                        e = E = max(v.begin(), E - 1);
                    }
                    else
                        v.erase(e);
                }
                else
                    e++;
            }
        }
        cout << (v.empty() ? "YES" : "NO") << endl;
    }
}