// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <list>
// max_size 0x28f5c28 = 0xffffffff / 0x64: element size.
struct Value25 { int words[25]; bool operator==(const Value25&) const; bool operator<(const Value25&) const; };
template class std::list<Value25>;
