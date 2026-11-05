// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <set>
struct Big { int k; char pad[0x150]; bool operator<(const Big& o) const { return k < o.k; } };
template class std::_Tree<std::_Tset_traits<Big, std::less<Big>, std::allocator<Big>, false> >;
