#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int m, n;
        cin >> m >> n;
        vector<pair<int, bool> > cuts;
        for (int i = 0; i < m - 1; i++)
        {
            int cost;
            cin >> cost;
            cuts.push_back({cost, true});
        }
        for (int i = 0; i < n - 1; i++)
        {
            int cost;
            cin >> cost;
            cuts.push_back({cost, false});
        }
        sort(cuts.begin(), cuts.end(), greater<pair<int, bool> >());
        int hc = 1, vc = 1;
        long long costs = 0;
        for (auto &cut : cuts)
        {
            if (cut.second)
            {
                vc++;
                costs += (long long)cut.first * hc;
            }
            else
            {
                hc++;
                costs += (long long)cut.first * vc;
            }
            costs %= (int)1e9 + 7;
        }
        cout << costs << endl;
    }
}