#include <iostream>
#include <vector>
#include <algorithm>
#define ALL(x) x.begin(), x.end()

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    int mid = n / 2;
    vector<pair<int, int>> ss1(1);
    for (int i = 0; i < mid; i++)
    {
        int s = ss1.size();
        for (int j = 0; j < s; j++)
        {
            int m1 = abs(ss1[j].first + x[i]);
            int m2 = abs(ss1[j].first - x[i]);
            ss1.push_back({m1, ss1[j].second | (1 << i)});
            if (m1 != m2)
                ss1.push_back({m2, ss1[j].second | (1 << i)});
        }
    }
    vector<pair<int, int>> ss2(1);
    for (int i = mid; i < n; i++)
    {
        int s = ss2.size();
        for (int j = 0; j < s; j++)
        {
            int m1 = abs(ss2[j].first + x[i]);
            int m2 = abs(ss2[j].first - x[i]);
            ss2.push_back({m1, ss2[j].second | (1 << i)});
            if (m1 != m2)
                ss2.push_back({m2, ss2[j].second || (1 << i)});
        }
    }
    sort(ALL(ss1));
    ss1.resize(unique(ALL(ss1)) - ss1.begin());
    sort(ALL(ss2));
    ss2.resize(unique(ALL(ss2)) - ss2.begin()); 
}