#include <iostream>
#define endl '\n'

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

using namespace std;

int main()
{
    //   ios_base::sync_with_stdio(false);
    //   cin.tie(NULL);
    int n, t, mask = 0;
    cin >> n >> t;
    while (t--)
    {
        int x;
        cin >> x;
        mask += 1 << x;
    }
    int k = mask;
    while (k < (1 << n))
    {
        if ((k & mask) == mask)
        {
            cout << k << ":";
            for (int i = 0; i < n; i++)
                if (k & (1 << i))
                    cout << ' ' << i;
            cout << endl;
        }
        k++;
    }
}
