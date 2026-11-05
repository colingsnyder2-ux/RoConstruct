// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>

// isnil at +0x71 (target cmp byte ptr [esi+0x71]): value_type 0x64 bytes.
struct Value24 { int words[24]; };
template class std::_Tree<std::_Tmap_traits<int, Value24, std::less<int>,
    std::allocator<std::pair<const int, Value24> >, false> >;
