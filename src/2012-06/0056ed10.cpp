// from server: 0% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>

// _Tree::_Buynode: new(0x28), Isnil at +0x25 = 0xd + sizeof(pair) -> pair is 0x18:
// an 8-byte, 4-aligned trivially copied key and a 0x10-byte mapped value with an out-of-line copy constructor.
struct Key8 { int words[2]; };
inline bool operator<(const Key8& l, const Key8& r) { return l.words[0] < r.words[0]; }
struct Mapped {
    Mapped(const Mapped&);
    ~Mapped();
    Mapped& operator=(const Mapped&);
    int words[4];
};
template class std::_Tree<std::_Tmap_traits<Key8, Mapped, std::less<Key8>,
    std::allocator<std::pair<const Key8, Mapped> >, false> >;
