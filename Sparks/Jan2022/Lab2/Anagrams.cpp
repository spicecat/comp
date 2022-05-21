#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;

int main()
{
    string w;
    set<string> words;
    map<string, int> dict;
    while (cin >> w)
    {
        if (w == "#")
            break;
        words.insert(w);
        for (auto &c : w)
            c = tolower(c);
        sort(w.begin(), w.end());
        dict[w]++;
    }
    for (auto c : words)
    {
        string w = c;
        for (auto &c : w)
            c = tolower(c);
        sort(w.begin(), w.end());
        if (dict[w] > 1)
            continue;
        cout << c << endl;
    }
}