// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>

// isnil at +0x31 (target cmp byte ptr [esi+0x31]): value_type 0x24 bytes.
struct Value8 { int words[8]; };
template class std::_Tree<std::_Tmap_traits<int, Value8, std::less<int>,
    std::allocator<std::pair<const int, Value8> >, false> >;
