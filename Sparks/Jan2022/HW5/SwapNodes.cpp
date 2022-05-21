#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define endl '\n'
#define lli long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define first f
#define second s

using namespace std;

struct node
{
    int left, right;
};
void swapNodes(int level, int n)
{
    if (n == -1)
        return;
    if (level % k == 0)
        swap(nodes[n].f, nodes[n].second);
    swapNodes(level + 1, nodes[n].f);
    swapNodes(level + 1, nodes[n].s);
}

int main()
{
    int n;
    cin >> n;
    nodes.pb({0, 0});
    while (n--)
    {
        int leftc, rightc;
        cin >> leftc >> rightc;
        nodes.pb({leftc, rightc});
    }
}