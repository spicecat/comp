#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;
int main()
{
  int k = 0;
  while (1)
  {
    k++;
    int t;
    cin >> t;
    if (t == 0)
      break;
    map<int, int> teams;
    for (int i = 0; i < t; i++)
    {
      int n;
      cin >> n;
      for (int j = 0; j < n; j++)
      {
        int x;
        cin >> x;
        teams.insert({x, i});
      }
    }
    cout << "Scenario #" << k << endl;
    queue<int> teamsQueue;
    queue<int> teamQueue[t];
    while (1)
    {
      string command, tmp;
      cin >> command;
      if (command == "STOP")
        break;
      if (command == "ENQUEUE")
      {
        cin >> tmp;
        int x = stoi(tmp);
        int team = teams[x];
        if (teamQueue[team].empty())
          teamsQueue.push(team);
        teamQueue[team].push(x);
      }
      else if (command == "DEQUEUE")
      {
        int team = teamsQueue.front();
        cout << teamQueue[team].front() << endl;
        teamQueue[team].pop();
        if (teamQueue[team].empty())
          teamsQueue.pop();
      }
    }
    cout << endl;
  }
}