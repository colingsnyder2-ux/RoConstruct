// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <list>
// max_size 0x30c30c3 = 0xffffffff / 0x54: element size.
struct Value21 { int words[21]; bool operator==(const Value21&) const; bool operator<(const Value21&) const; };
template class std::list<Value21>;
