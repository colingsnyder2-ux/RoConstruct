// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>

// value_type is 0x48 bytes: isnil at +0x0x55 (from target cmp byte ptr [esi+0x0x55]).
struct Value17 { int words[17]; };
template class std::_Tree<std::_Tmap_traits<int, Value17, std::less<int>,
    std::allocator<std::pair<const int, Value17> >, false> >;
