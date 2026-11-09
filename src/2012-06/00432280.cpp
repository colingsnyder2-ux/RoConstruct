// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <list>
// max_size 0xcccccc = 0xffffffff / 0x140: element size.
struct Value80 { int words[80]; bool operator==(const Value80&) const; bool operator<(const Value80&) const; };
template class std::list<Value80>;
