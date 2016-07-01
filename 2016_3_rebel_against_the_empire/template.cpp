#include <algorithm>
#include <memory>
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

struct Asteroid
{
  using Ptr = std::shared_ptr<Asteroid>;
  using ConstPtr = std::shared_ptr<const Asteroid>;

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

  Asteroid()  {}
  Asteroid(Vector3d pos, Vector3d vel)
    : position(pos)
    , velocity(vel)
  {}

  Vector3d position;
  Vector3d velocity;
};

struct Cluster
{
  Cluster() {}
  Cluster(const auto& asteroids, auto velocity)
    : asteroids(asteroids)
    , velocity(velocity)
  {}
  Cluster(const auto& asteroid)
    : asteroids({asteroid})
    , velocity(asteroid->velocity)
  {}

  double getMaxJumpDistance(Asteroid::ConstPtr start, Asteroid::ConstPtr end)
  {
    const auto s = find(asteroids.cbegin(), asteroids.cend(), start);
    if (s == asteroids.cend())
      throw (int)1;

    size_t index_start = std::distance(asteroids.cbegin(), s);

    const auto e = find(asteroids.cbegin(), asteroids.cend(), end);
    if (e == asteroids.cend())
      throw (int)2;

    size_t index_end = std::distance(asteroids.cbegin(), e);

    vector<bool> explored(asteroids.size(), false);
    explored[index_start] = true;
    double max_jump = 0.0;

    size_t added = 0;
    do
    {
      double smallest_jump = std::numeric_limits<double>::max();

      loop(ex, explored.size())
      {
        if (!explored[ex])
          continue;

        loop(unex, explored.size())
        {
          if (explored[unex])
            continue;

          const auto jump = getWeight(ex, unex);
          if (jump < smallest_jump)
          {
            smallest_jump = jump;
            added = unex;
          }
          
        }

      }

      if (smallest_jump > max_jump)
        max_jump = smallest_jump;

      explored[added] = true;
    }
    while (added != index_end);

    return sqrt(max_jump);
  }

  const vector<Asteroid::ConstPtr> getAllReachedAsteroids(Asteroid::ConstPtr start, double max_jump)
  {
    max_jump = max_jump*max_jump;

    const auto s = find(asteroids.cbegin(), asteroids.cend(), start);
    if (s == asteroids.cend())
      throw (int)3;

    vector<Asteroid::ConstPtr> reached({start});
    size_t index_start = std::distance(asteroids.cbegin(), s);

    vector<bool> explored(asteroids.size(), false);
    explored[index_start] = true;

    size_t added;
    do
    {
      added = asteroids.size();

      loop(ex, explored.size())
      {
        if (!explored[ex])
          continue;

        loop(unex, explored.size())
        {
          if (explored[unex])
            continue;

          if (getWeight(ex, unex) <= max_jump)
          {
            added = unex;
            explored[unex] = true;
            break;
          }
          
        }
        if (added != asteroids.size())
          break;

      }

      reached.push_back(asteroids[added]);

    }
    while (added < asteroids.size());

    return reached;
  }

  vector<Asteroid::Ptr> asteroids;
  Vector3d velocity;

  double getWeight(size_t first, size_t second) const
  {
    assert(first != second);
    const auto min_index = min(first, second);
    const auto max_index = max(first, second);
    return weights[min_index][max_index-min_index-1];
  }
  void calcWeights()
  {
    weights.resize(asteroids.size() - 1);
    loop(ii, asteroids.size() - 1)
    {
      weights[ii].reserve(asteroids.size() - ii - 1); 
      for (size_t jj = ii + 1; jj < asteroids.size(); ++jj)
      {
        weights[ii].push_back((asteroids[ii]->position - asteroids[jj]->position).squaredNorm());
      }
    }
  }
  vector<vector<double>> weights;
};


int main()
{
  size_t num_test_cases;
  cin >> num_test_cases;

  for (size_t i = 0; i < num_test_cases; i++)
  {
    size_t N, S;
    cin >> N >> S;

    vector<Asteroid::Ptr> asteroids;
    asteroids.reserve(N);

    loop(ii, N)
    {
      Vector3d pos;
      Vector3d vel;

      cin >> pos[0] >> pos[1] >> pos[2]
          >> vel[0] >> vel[1] >> vel[2];

      Asteroid a;
      a.position = pos;
      a.velocity = vel;
      asteroids.emplace_back(make_shared<Asteroid>(pos, vel));
    }

    // sort into clusters
    vector<Cluster> clusters;
    for (const auto& a : asteroids)
    {
      const auto it = std::find_if(clusters.begin(), clusters.end(), [&a](const vector<Cluster>::value_type& c){
          return c.velocity == a->velocity;});

      if (it == clusters.end())
      {
        clusters.emplace_back(a);
      }
      else
      {
        it->asteroids.push_back(a);
      }
    }

    //cout <<"Number of clusters: " <<clusters.size() <<endl;
    for (auto& a : clusters)
      a.calcWeights();

    if (clusters.size() == 1)
    {
      double res = clusters.front().getMaxJumpDistance(asteroids[0], asteroids[1]);
      std::cout <<"Case #" <<(i+1) <<": "  <<setprecision(10) <<res <<endl;
    }

    

  }
  
  return 0;
}
