#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        int x;
        cin >> x;
        if (x == 0)
            break;
        cout << x;
    }
}