// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <set>

// isnil at +0x11 (target cmp byte ptr [esi+0x11]) -> value_type 4 bytes.
template class std::_Tree<std::_Tset_traits<int, std::less<int>, std::allocator<int>, false> >;
