#include <iostream>
#include <list>
#include <string>

int main()

{
    std::string line;
    while (std::getline(std::cin, line) && line != "")
    {
        std::list<char> res;
        std::list<char>::iterator pos = res.begin();
        for (char c : line)
            if (c == '[')
                pos = res.begin();
            else if (c == ']')
                pos = res.end();
            else
                res.insert(pos, c);
        for (char c : res)
            std::cout << c;
        std::cout << '\n';
    }
}