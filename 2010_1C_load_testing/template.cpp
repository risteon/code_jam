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
    double a,b;
    uint32_t c;
    cin >> a >> b >> c;

    double x = 0.0;
    if ((b/a) > c)
    {
      x = log(log(b/a) / log(c))/log(2);
    }

    std::cout <<"Case #" <<(i+1) <<": " <<static_cast<uint32_t>(ceil(x)) <<endl;

  }
  
  return 0;
}
