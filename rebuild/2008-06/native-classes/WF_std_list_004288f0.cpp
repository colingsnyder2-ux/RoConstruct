// native-flags: /O2 /GS- /EHsc /MD
// NEEDS-DECL: stand-in for the original element type E (sizeof == 320); std::bitset<2560> is used because no types may be defined here
#include <list>
#include <bitset>

typedef std::bitset<2560> E;

void use_list(std::list<E>& l, const E& e)
{
  l.push_back(e);
}

void make_list()
{
  std::list<E> l;
  E e;
  l.push_back(e);
}
