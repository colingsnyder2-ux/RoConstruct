// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>

// isnil at +0x3d (target cmp byte ptr [esi+0x3d]): value_type 0x30 bytes.
struct Value11 { int words[11]; };
template class std::_Tree<std::_Tmap_traits<int, Value11, std::less<int>,
    std::allocator<std::pair<const int, Value11> >, false> >;
