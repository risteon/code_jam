#include <map>
#include <vector>
#include <assert.h>
#include <iostream>
#include <cstdint>
#include <string>

int main(int argc, char** argv)
{
  using ui = uint64_t;

  ui n;
  std::cin >> n;
  for (ui nn = 0; nn < n; ++nn)
  {
    std::string s;
    std::cin >> s;  
    std::vector<ui> numbers(10, 0);

    std::map<char, ui> v;
    v['E'] = 0;
    v['F'] = 0;
    v['G'] = 0;
    v['H'] = 0;
    v['I'] = 0;
    v['N'] = 0;
    v['O'] = 0;
    v['R'] = 0;
    v['S'] = 0;
    v['T'] = 0;
    v['U'] = 0;
    v['V'] = 0;
    v['W'] = 0;
    v['X'] = 0;
    v['Z'] = 0;

    for (char c : s)
    {
      v[c]++;
    }
    
    ui nz = v['Z'];
    numbers[0] = nz;
    v['E'] -= nz;
    v['O'] -= nz;
    v['R'] -= nz;

    ui nw = v['W'];
    numbers[2] = nw;
    v['O'] -= nw;
    v['T'] -= nw;

    ui nx = v['X'];
    numbers[6] = nx;
    v['I'] -= nx;
    v['S'] -= nx;
    
    ui nu = v['U'];
    numbers[4] = nu;
    v['F'] -= nu;
    v['O'] -= nu;
    v['R'] -= nu;

    ui ng = v['G'];
    numbers[8] = ng;
    v['E'] -= ng;
    v['I'] -= ng;
    v['H'] -= ng;
    v['T'] -= ng;

    ui nh = v['H'];
    numbers[3] = nh;
    v['T'] -= nh;
    v['E'] -= 2*nh;
    v['R'] -= nh;

    ui ns = v['S'];
    numbers[7] = ns;
    v['E'] -= 2*ns;
    v['V'] -= ns;
    v['N'] -= ns;

    ui nv = v['V'];
    numbers[5] = nv;
    v['F'] -= nv;
    v['I'] -= nv;
    v['E'] -= nv;

    ui no = v['O'];
    numbers[1] = no;
    v['N'] -= no;
    v['E'] -= no;

    numbers[9] = v['E'];

    std::cout <<"Case #" <<nn+1 <<": ";
    for (ui aa = 0; aa < 10; ++aa)
    {
      for (ui bb = 0; bb < numbers[aa]; ++bb)
      {
        std::cout <<aa;
      }
    }
    std::cout <<std::endl;

  }

  return 0;
}
