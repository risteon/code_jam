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

int main()
{
  size_t num_test_cases;
  cin >> num_test_cases;

  for (size_t i = 0; i < num_test_cases; i++)
  {
    size_t ropes;
    cin >> ropes;

    vector<pair<uint16_t, uint16_t>> coord(ropes);

    size_t intersections = 0;

    for (size_t r = 0; r < ropes; ++r)
    {
      cin >> coord[r].first;
      cin >> coord[r].second;
    }


    for (size_t r = 0; r < ropes; ++r)
    {
      for (size_t other = r + 1; other < ropes; ++other)
      {
        const bool a = coord[r].first > coord[other].first;
        if (a != (coord[r].second > coord[other].second))
        {
          ++intersections;
        }
      }
    }


    std::cout <<"Case #" <<(i+1) <<": " <<intersections  <<endl;

  }
  
  return 0;
}
