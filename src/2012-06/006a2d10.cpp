// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>

// value_type is 0x2c bytes: isnil at +0x0x39 (from target cmp byte ptr [esi+0x0x39]).
struct Value10 { int words[10]; };
template class std::_Tree<std::_Tmap_traits<int, Value10, std::less<int>,
    std::allocator<std::pair<const int, Value10> >, false> >;
