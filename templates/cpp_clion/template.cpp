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
#undef NDEBUG
#include <cassert>

#include "io_redirect.h"

#define FOR(i, a, b) for(std::size_t (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) std::cout << #x <<" = " <<(x) <<std::endl;


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
