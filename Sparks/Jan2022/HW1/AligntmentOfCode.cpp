#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int wlen[90] = {0};
string strs[90][1000];

int main()
{
    string line;
    int l;
    for (l = 0; getline(cin, line); l++)
    {
        int off = line.find_first_not_of(' ');
        if (off < 0)
            break;

        int j;
        for (j = 0;; j++)
        {
            int end = line.find_first_of(' ', off);
            if (end < 0)
                end = line.size();

            wlen[j] = max((int)(strs[l][j] = line.substr(off, end - off)).length(), wlen[j]);

            off = line.find_first_not_of(' ', end);
            if (off < 0)
                break;
        }
        strs[l][j + 1] = "";
    }

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; strs[i][j] != ""; j++)
        {
            cout << strs[i][j];
            for (int s = strs[i][j].size(); s <= wlen[j]; s++)
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}