#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define endl '\n'
#define lli long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define f first
#define s second

using namespace std;

void print(vi v)
{
  for (int c : v)
    cout << c << ',';
  cout << '\n';
}

struct node
{
  int x, y;
  node *left, *right;
};

int A[100], n = 4, used[101];
int main()
{
  // int a, b = 9;
  // cout << &a << 987654321;
  // node *root = new node(), *A = new node();
  // root->left = A;
  // int arr[] = {1, 3, 3, 7};
  // sort(arr, arr + 4);
  // do
  // {
  //   cout << arr[0] << arr[1] << arr[2] << arr[3] << endl;
  // } while (next_permutation(arr, arr + 4));
  bitset<8> bset1("1100");
  cout << bset1.count();
}