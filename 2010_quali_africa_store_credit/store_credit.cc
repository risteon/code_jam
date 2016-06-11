#include <vector>
#include <assert.h>
#include <iostream>
#include <cstdint>

int main(int argc, char** argv)
{
  using ui = uint64_t;
  ui n;
  std::cin >> n;

  for (ui j = 0; j < n; ++j)
  {
    ui c;
    std::cin >> c;

    ui i;
    std::cin >> i;

    std::vector<ui> prices;
    prices.reserve(i);
    for (ui item = 0; item < i; ++item)
    {
      ui p;
      std::cin >> p;
      prices.push_back(p);
    }

    bool found = false;
    ui item, test;

    for (item = 0; item < i; ++item)
    {
      for (test = item+1; test < i; ++test)
      {
        if (prices[item] + prices[test] == c)
        {
          found = true;
          break;
        }
         
      }
      if (found)
        break;
    }

    assert(found);

    std::cout <<"Case #" <<(j+1) <<": " <<item+1 <<" " <<test+1 <<std::endl;
  }

  return 0;
}
