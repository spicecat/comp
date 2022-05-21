#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

int main()
{
  std::set<std::string> dict, res;
  std::string line;
  while (std::getline(std::cin, line) && line != "")
    dict.insert(line);
  std::vector<std::string> firsts;
  for (std::string compound : dict)
  {
    for (std::vector<std::string>::iterator first = firsts.begin(); first != firsts.end();)
    {
      int l1 = (*first).length();
      if (compound.length() > l1 && compound.rfind(*first, 0) == 0)
      {
        if (dict.find(compound.substr(l1)) != dict.end())
          res.insert(compound);
        first++;
      }
      else
        firsts.erase(first);
    }
    firsts.push_back(compound);
  }
  for (std::string compound : res)
    std::cout << compound << '\n';
}