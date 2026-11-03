// from server: 93% by EspClaude
// roc 2007-08 004a28d0  std::map<int, std::vector<E>>::_Buynode (E = 12-byte POD; VS2005 xtree try/catch(...) deallocate)
// roc-flags: /O2 /GS /EHsc /MD
#include <map>
#include <vector>
struct E { int v[3]; };
template class std::_Tree<std::_Tmap_traits<int, std::vector<E>, std::less<int>, std::allocator<std::pair<const int, std::vector<E> > >, false> >;
