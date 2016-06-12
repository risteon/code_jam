#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <numeric>
#undef N_DEBUG
#include <assert.h>

using namespace std;

int main()
{
  size_t num_test_cases;
  cin >> num_test_cases;

  for (size_t i = 0; i < num_test_cases; i++)
  {
    string s;
    cin >> s;
    vector<bool> mood(s.size());

    for (size_t i = 0; i < s.size(); ++i)
    {
      mood[i] = s[i] == 'C' ? true : false;
    }

    stack<bool> stack;
    uint64_t score = 0;

    for (uint64_t step = 0; step < mood.size(); ++step)
    {
      if (stack.empty())
      {
        stack.push(mood[step]);
      }
      else
      {
        if (stack.size() == mood.size() - step)
        {
          score += stack.top() == mood[step] ? 10 : 5;
          stack.pop();
        }
        else if (stack.top() == mood[step])
        {
          stack.pop();
          score += 10;
        }
        else
        {
          stack.push(mood[step]);
        }

      }
    }


    std::cout <<"Case #" <<(i+1) <<": "  <<score <<endl;

  }
  
  return 0;
}
