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
  using Int = int64_t;
  
  size_t num_test_cases;
  cin >> num_test_cases;

  for (size_t i = 0; i < num_test_cases; i++)
  {
    size_t vs;
    cin >> vs;

    assert(vs > 0 && "Wrong input parsing");

    vector<Int> a(vs);
    vector<Int> b(vs);

    for (size_t i = 0; i < vs; i++)
    {
      cin >> a[i];
    }
    for (size_t i = 0; i < vs; i++)
    {
      cin >> b[i];
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end(), std::greater<int>());

    Int min = 0;
    for (size_t i = 0; i < vs; i++)
    {
      min += a[i] * b[i];
    }

    std::cout <<"Case #" <<(i+1) <<": " <<min <<endl;

  }
  
  return 0;
}
