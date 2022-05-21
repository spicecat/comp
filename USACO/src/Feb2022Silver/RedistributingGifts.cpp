#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define endl '\n'
#define lli long long int
#define vi vector<int>

using namespace std;

bool check(int id, int x, vector<pair<vi, int>> v)
{
    v.erase(v.begin() + id);
    for (int i = 0; i < v.size(); i++)
    {
        vi::iterator it = find(ALL(v[i].first), x);
        if (it != v[i].first.end())
            v[i].first.erase(it);
        if (i != id && v[i].first.empty())
            return false;
    }
    double freq[501] = {};
    bool valid = true;
    for (int i = 0; i < v.size(); i++)
    {
        bool valid2 = false;
        for (int c : v[i].first)
        {
            if (freq[c] < 1)
                valid2 = true;
            freq[c] += 1 / v[i].first.size();
        }
        if (!valid2)
        {
            valid = false;
            break;
        }
    }
    return valid;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<vi, int>> v(N);
    vi res(N);
    for (int i = 0; i < N; i++)
    {
        vi tmp;
        bool add = true;
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;
            if (add)
            {
                add = x != i + 1;
                tmp.pb(x);
            }
        }
        v[i] = {tmp, i};
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first.size() == 1)
        {
            int x = v[i].first[0];
            res[v[i].second] = x;
            for (int j = 0; j < v.size(); j++)
            {
                vi::iterator it = find(ALL(v[j].first), x);
                if (it != v[j].first.end())
                    v[j].first.erase(it);
            }
            v.erase(v.begin() + i);
            i = -1;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].first.size(); j++)
        {
            int x = v[i].first[j];
            if (check(i, x, v))
            {
                res[v[i].second] = x;
                break;
            }
        }
    }
    for (int c : res)
        cout << c << endl;
}