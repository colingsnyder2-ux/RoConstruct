// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>

// isnil at +0x29 (target cmp byte ptr [esi+0x29]) -> value_type 0x1c bytes.
// Head pointer at tree+0x10 (target mov ecx,[ecx+0x10]) vs +4 with an empty
// comparator: the comparator object is one word (12-byte comparator compiled to +0x18).
struct Value6 { int words[6]; };
struct Less4 {
    int state;
    bool operator()(int a, int b) const { return a < b; }
};
template class std::_Tree<std::_Tmap_traits<int, Value6, Less4,
    std::allocator<std::pair<const int, Value6> >, false> >;