#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ALL(x) x.begin(), x.end()
#define endl '\n'

using namespace std;

bool alldigits(int i, int j)
{
    string a = to_string(i), b = to_string(j);
    if (i < 10000)
        a = "0" + a;
    if (j < 10000)
        b = "0" + b;
    a = a + b;
    sort(ALL(a));
    return a == "0123456789";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, f = 1;
    while (cin >> N)
    {
        if (N == 0)
            break;
        if (f++ != 1)
            cout << endl;
        bool flag = false;
        for (int i = 1234; i <= 98765 / N; i++)
        {
            int j = i * N;
            if (alldigits(i, j))
            {
                cout << j << " / ";
                if (i < 10000)
                    cout << "0";
                cout << i << " = " << N << endl;
                flag = true;
            }
        }
        if (!flag)
            cout << "There are no solutions for " << N << "." << endl;
    }
}