// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>

// value_type size from max_size immediate: 0xFFFFFFFF/(imm+1) = 72 bytes.
struct ValueN { int words[17]; };
template class std::_Tree<std::_Tmap_traits<int, ValueN, std::less<int>,
    std::allocator<std::pair<const int, ValueN> >, false> >;
