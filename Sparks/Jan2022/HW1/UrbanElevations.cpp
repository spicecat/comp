#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main()
{
    struct Point
    {
        int x, y;
    };
    Point A;
    A.x = 10;
    A.y = 20;

    pair<int, int> B{1, 2};
    cout << B.first;
}