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

#include "io_redirect.h"

#define loop(x,n) for(std::size_t (x) = 0; (x) < (n); ++(x))


using namespace std;

using UInt = uint64_t;
using Int = int64_t;

int main(int argc, char* argv[])
{
  //////////////////////// INPUT/OUTPUT //////////////////////////
  if (!redirect_io(argc, argv))
    return 0;
  ////////////////////////////////////////////////////////////////

  
  size_t num_test_cases;
  cin >> num_test_cases;

  for (size_t i = 0; i < num_test_cases; ++i)
  {
    size_t vs;
    cin >> vs;


    std::cout <<"Case #" <<(i+1) <<": "  <<endl;

  }


  ////////////////////////////////////////////////////////////////
  cleanup_io();
  return 0;
}
