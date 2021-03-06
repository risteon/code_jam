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

double getMinDistance(Asteroid::ConstPtr a, Asteroid::ConstPtr b)
{
  const auto w = a->position - b->position;
  const auto v = a->velocity - b->velocity;
  const auto t_cpa = -w.dot(v) / v.squaredNorm();
  const auto p_a = a->position + t_cpa * a->velocity;
  const auto p_b = b->position + t_cpa * b->velocity;
  return (p_a - p_b).norm();
}

double getMinDistanceWithin(Asteroid::ConstPtr a, Asteroid::ConstPtr b, double t_min, double t_max)
{
  const auto w = a->position - b->position;
  const auto v = a->velocity - b->velocity;
  const auto t_cpa = -w.dot(v) / v.squaredNorm();

  double t;
  if (t_cpa < t_min)
    t = t_min;
  else if (t_cpa > t_max)
    t = t_max;
  else
    t = t_cpa;

  const auto p_a = a->position + t * a->velocity;
  const auto p_b = b->position + t * b->velocity;
  return (p_a - p_b).norm();
}

struct Edge
{
  Edge(size_t first, size_t second, double weight)
    : first_vertex(first)
    , second_vertex(second)
    , weight(weight)
  {}
  size_t first_vertex;
  size_t second_vertex;
  double weight;

  bool operator <(const Edge& other) const
  {
    if (weight != other.weight)
      return weight < other.weight;
    if (first_vertex != other.first_vertex)
      return first_vertex < other.first_vertex;
    return second_vertex < other.second_vertex;
  }
  bool contains(size_t vertex) const  { return first_vertex == vertex || second_vertex == vertex; }
  size_t getOther(size_t vertex) const
  {
    if (first_vertex == vertex)
      return second_vertex;
    return first_vertex;
  }
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

  double getMaxJumpDistance(Asteroid::ConstPtr start, Asteroid::ConstPtr end) const
  {
    const auto s = find(asteroids.cbegin(), asteroids.cend(), start);
    if (s == asteroids.cend())
      throw (int)1;

    size_t index_start = std::distance(asteroids.cbegin(), s);

    const auto e = find(asteroids.cbegin(), asteroids.cend(), end);
    if (e == asteroids.cend())
      throw (int)2;

    size_t index_end = std::distance(asteroids.cbegin(), e);

    auto unexplored = edges;
    set<size_t> explored;
    explored.insert(index_start);
    double max_jump = 0.0;
    size_t added = 0;
    do
    {
      for (auto it = unexplored.begin(); it != unexplored.end(); it++)
      {
        const auto first_it = explored.find(it->first_vertex);
        const auto second_it = explored.find(it->second_vertex);

        auto ex = explored.cend();
        if (first_it != explored.cend())
          ex = first_it;
        else if (second_it != explored.cend())
          ex = second_it;
        else
          continue;

        added = it->getOther(*ex);
        explored.insert(added);
        if (it->weight > max_jump)
          max_jump = it->weight;
        unexplored.erase(it);

        break;
      }
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
        edges.emplace(ii, jj, weights[ii].back());
      }
    }
  }
  vector<vector<double>> weights;
  set<Edge> edges;
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

    double res = 0.0;
    if (clusters.size() == 1)
    {
      res = clusters.front().getMaxJumpDistance(asteroids[0], asteroids[1]);
      std::cout <<"Case #" <<(i+1) <<": "  <<setprecision(10) <<res <<endl;
    }
    else
    {
      if (asteroids[0]->velocity != asteroids[1]->velocity)
        res = getMinDistanceWithin(asteroids[0], asteroids[1], 0.0, S);
      else
        res = -1.0;

      std::cout <<"Case #" <<(i+1) <<": "  <<setprecision(10) <<res <<endl;
    }

    

  }
  
  return 0;
}
