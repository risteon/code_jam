#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <numeric>
#undef N_DEBUG
#include <assert.h>

using namespace std;

using Int = int64_t;

int main()
{
  size_t l, d, n;
  cin >> l >> d >> n;

  vector<string> known_words;

  for (size_t i = 0; i < d; i++)
  {
    string s;
    cin >> s;
    known_words.push_back(s);
  }

  for (size_t i = 0; i < n; i++)
  {
    string line;
    cin >> line;
    size_t pos = 0;

    vector<vector<char>> poss(l);

    for (size_t j = 0; j < l; j++)
    {
      if (line[pos] == '(')
      {
        ++pos;
        while (line[pos] != ')')
        {
          poss[j].push_back(line[pos]);
          ++pos;
        }
        ++pos;
        assert(!poss[j].empty());
      }
      else
      {
        poss[j].push_back(line[pos]);
        ++pos;
      }
    }


    Int matches = 0;

    for (const auto& str : known_words)
    {
      bool cont = false;
      for (size_t p = 0; p < l; p++)
      {
        if (std::find(poss[p].cbegin(), poss[p].cend(), str[p]) == poss[p].cend())
        {
          cont = true;
          continue;
        }
      }
      if (cont)
      {
        continue;
      }
      ++matches;
    }

    cout <<"Case #" <<(i+1) <<": " <<matches <<endl;
  }
  
  return 0;
}
