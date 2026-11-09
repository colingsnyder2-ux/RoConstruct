// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <list>
// max_size 0x3ffffff = 0xffffffff / 0x40: element size.
struct Value16 { int words[16]; bool operator==(const Value16&) const; bool operator<(const Value16&) const; };
template class std::list<Value16>;
