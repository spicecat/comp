#include <iostream>
#include <vector>
#include <climits>
#define endl '\n'
using namespace std;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, maxSubarr = INT_MIN, minps = 0, posSum = 0, maxEle = INT_MIN;
        cin >> n;
        vi x(n + 1), ps(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
            ps[i] = ps[i - 1] + x[i];
            maxSubarr = max(maxSubarr, ps[i] - minps);
            minps = min(minps, ps[i]);
            maxEle = max(maxEle, x[i]);
            if (x[i] > 0)
                posSum += x[i];
        }
        cout << maxSubarr << ' ' << (posSum ? posSum : maxEle) << endl;
    }
}