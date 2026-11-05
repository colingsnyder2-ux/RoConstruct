// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>

// value_type is 0x20 bytes: node color at +0x2c, isnil at +0x2d, max_size 0x7ffffff.
struct Value28 { int words[7]; };
template class std::_Tree<std::_Tmap_traits<int, Value28, std::less<int>,
    std::allocator<std::pair<const int, Value28> >, false> >;
