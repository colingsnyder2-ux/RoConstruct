// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <list>
// max_size 0x71c71c7 = 0xffffffff / 0x24: element size.
struct Value9 { int words[9]; bool operator==(const Value9&) const; bool operator<(const Value9&) const; };
template class std::list<Value9>;
