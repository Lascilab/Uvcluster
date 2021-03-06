#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
bool luhn( const string& id)
{
  static const int m[10]  = {0,2,4,6,8,1,3,5,7,9}; // mapping for rule 3
  bool is_odd_dgt = false;
  auto lambda = [&](int a, char c) {return a + ((is_odd_dgt = !is_odd_dgt) ? c-'0' : m[c-'0']);};
  int s = std::accumulate(id.rbegin(), id.rend(), 0, lambda);
  return 0 == s%10;
}
 
int main( int argc, char *argv[] )
{
  auto print = [](const string & s) {cout << "La tarjeta "<< s << " es " << (luhn(s)?"válida":"invalida") << endl;};
  print(argv[1]);
  return 0;
}
