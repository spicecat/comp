#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <algorithm>
#define loop(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define endl '\n'
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

struct comp
{
    bool operator()(const pair<pii, int> &a, const pair<pii, int> &b) const
    {
        return a.f.s < b.f.s;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<pii, int>> points(n);
    loop(i, n)
    {
        int a, b;
        cin >> a >> b;
        points.pb({{a, b}, i});
    }
    sort(ALL(points));
    set<pair<pii, int>, comp> active;
    double res = 1e25;
    pii resp;
    int l = 0;
    loop(i, n)
    {
        while (points[l].f.f < points[i].f.f - res)
            active.erase(points[l++]);
        for (auto k : active)
        {
            if (k.f.s < points[i].f.s - res)
                continue;
            double d = pow(points[i].f.f - k.f.f, 2) + pow(points[i].f.s - k.f.s, 2);
            if (d < res)
            {
                res = d;
                resp = {points[i].s, k.s};
            }
            if (k.f.s > points[i].f.s + res)
                break;
        }
        active.insert(points[i]);
    }
    cout << resp.s << ' ' << resp.f << ' ' << setprecision(6) << fixed << sqrt(res) << endl;
}