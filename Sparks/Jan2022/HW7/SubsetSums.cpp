#include <iostream>
#include <algorithm>
#include <vector>
#define vi vector<int>
#define ALL(x) x.begin(), x.end()
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

using namespace std;
void generateSubsets(int start, int Num, int *arr, vi &vect)
{
  for (int mask = 0, sum; mask < (1 << Num); mask++)
  {
    sum = 0;
    for (int item = 0; item < Num; item++)
      if (mask & (1 << item))
        sum += arr[item + start];
    vect.push_back(sum);
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, A, B;
  cin >> N >> A >> B;
  int arr[35];
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  vi left, right;
  generateSubsets(0, N / 2, arr, left);
  generateSubsets(N / 2, N & 1 ? N / 2 + 1 : N / 2, arr, right);
  sort(ALL(right));

  vi::iterator low, high;
  unsigned long long ans = 0;
  for (int i = 0; i < left.size(); i++)
    ans += (upper_bound(ALL(right), B - left[i]) - right.begin()) - (lower_bound(ALL(right), A - left[i]) - right.begin());
  cout << ans << endl;
}