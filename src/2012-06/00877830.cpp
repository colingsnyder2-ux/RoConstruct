// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <set>

// isnil at +0xe (target cmp byte ptr [esi+0xe]): 1-byte value_type.
template class std::_Tree<std::_Tset_traits<char, std::less<char>,
    std::allocator<char>, false> >;
