// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>

// isnil at +0x0x59 (target cmp byte ptr [esi+0x0x59]) -> value_type 0x4c bytes.
struct Value18 { int words[18]; };
template class std::_Tree<std::_Tmap_traits<int, Value18, std::less<int>,
    std::allocator<std::pair<const int, Value18> >, false> >;
