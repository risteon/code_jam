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
#include <Eigen/Dense>
#undef NDEBUG
#include <cassert>

#include "io_redirect.h"

#define FOR(i, a, b) for(std::size_t (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) std::cout << #x <<" = " <<(x) <<std::endl;


using namespace std;

using UInt = uint64_t;
using Int = int64_t;


static const std::vector<std::string> NUMBERS = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main(int argc, char* argv[])
{
  //////////////////////// INPUT/OUTPUT //////////////////////////
  if (!redirect_io(argc, argv))
    return 0;
  ////////////////////////////////////////////////////////////////


  std::set<char> a;
  for (const auto& n : NUMBERS)
    for (const char c : n)
      a.insert(c);

  Eigen::MatrixXd m(a.size(), NUMBERS.size());
  m.setZero();

  REP(i, NUMBERS.size())
  {
    REP(j, NUMBERS[i].size())
    {
      const auto d = std::distance(a.cbegin(), a.find(NUMBERS[i][j]));
      m(d, i) += 1;
    }
  }

  size_t num_test_cases;
  cin >> num_test_cases;

  for (size_t i = 0; i < num_test_cases; ++i)
  {
    std::string vs;
    cin >> vs;

    Eigen::VectorXd b(a.size());
    b.setZero();
    REP(c, vs.size())
    {
      const auto d = std::distance(a.cbegin(), a.find(vs[c]));
      b(d) += 1;
    }
    const Eigen::VectorXd x = m.fullPivHouseholderQr().solve(b);

    string o{};
    REP(c, NUMBERS.size())
    {
      const size_t count = static_cast<size_t>(std::round(x(c)));
      REP(d, count)
      {
        o += std::to_string(c);
      }
    }
    std::cout <<"Case #" <<(i+1) <<": " <<o <<endl;
  }


  ////////////////////////////////////////////////////////////////
  cleanup_io();
  return 0;
}
