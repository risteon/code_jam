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
    size_t n_w;
    cin >> n_w;
    vector<string> first{};
    vector<string> second{};
    first.reserve(n_w);
    second.reserve(n_w);
    REP(j, n_w)
    {
      string s;
      cin >> s;
      first.push_back(s);
      cin >> s;
      second.push_back(s);
    }

    struct Edge
    {
        vector<string> free;
        vector<string> used;
    };
    using Vertex = map<string, Edge>;
    using IO = vector<string>;

    IO input{};
    IO output{};
    Vertex left;
    Vertex right;
    REP(j, first.size())
    {
      const auto it = left.find(first[j]);
      if (it == left.cend())
      {
        Edge e{};
        e.free.push_back(second[j]);
        left.emplace(first[j], std::move(e));
        input.push_back(first[j]);
      }
      else
      {
        it->second.free.push_back(second[j]);
      }
      const auto it_s = right.find(second[j]);
      if (it_s == right.cend())
      {
        Edge e{};
        e.free.push_back(first[j]);
        right.emplace(second[j], std::move(e));
        output.push_back(second[j]);
      }
      else
      {
        it_s->second.free.push_back(first[j]);
      }
    }

    REP(j, input.size())
    {
      if (!left[input[j]].free.empty())
      {

      }
    }


    std::cout <<"Case #" <<(i+1) <<": "  <<endl;

  }


  ////////////////////////////////////////////////////////////////
  cleanup_io();
  return 0;
}
