#include <iostream>
#include <vector>
#define pb push_back
#define endl '\n'
#define vi vector<int>
using namespace std;

void alg(vi &pre, int pre_s, int pre_e,
         vi &in, int in_s, int in_e,
         vi &post, int post_s, int post_e)
{
    int root = pre[pre_s];
    post[post_e] = root;
    for (int i = in_s; i <= in_e; i++)
        if (in[i] == root)
        {
            int sizeLeft = i - in_s, sizeRight = in_e - i;
            if (sizeLeft > 0)
                alg(pre, pre_s + 1, pre_s + sizeLeft,
                    in, in_s, i - 1,
                    post, post_s, post_s + sizeLeft - 1);
            if (sizeRight > 0)
                alg(pre, pre_s + sizeLeft + 1, pre_e,
                    in, i + 1, in_e,
                    post, post_s + sizeLeft, post_e - 1);
            break;
        }
}

int main()
{
    int n;
    cin >> n;
    vi preorder(n), inorder(n), postorder(n);
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    alg(preorder, 0, n - 1, inorder, 0, n - 1, postorder, 0, n - 1);
    for (int i = 0; i < n - 1; i++)
        cout << postorder[i] << ' ';
    cout << postorder[n - 1] << endl;
}