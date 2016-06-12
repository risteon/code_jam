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

#undef N_DEBUG
#include <assert.h>

#define loop(x,n) for(std::size_t (x) = 0; (x) < (n); ++(x))


using namespace std;

using UInt = uint64_t;
using Int = int64_t;
using Vector3d = Eigen::Matrix<double, 3, 1>;

struct Thing
{
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

  Vector3d position;
  Vector3d velocity;
};


int main()
{
  size_t num_test_cases;
  cin >> num_test_cases;

  for (size_t i = 0; i < num_test_cases; i++)
  {
    size_t vs;
    cin >> vs;


    std::cout <<"Case #" <<(i+1) <<": "  <<endl;

  }
  
  return 0;
}
