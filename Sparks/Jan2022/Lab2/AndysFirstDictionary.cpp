#include <iostream>
#include <string>
#include <set>
#include <cctype>
using namespace std;
int main()
{
    set<string> dict;
    string word;
    while (cin >> word)
    {
        string output;
        for (auto c : word)
        {
            if (isalpha(c))
                output += tolower(c);
            else
            {
                if (output.size())
                    dict.insert(output);
                output = "";
            }
        }
        if (output.size())
            dict.insert(output);
    }
    for (auto c : dict)
    {
        cout << c << endl;
    }
}