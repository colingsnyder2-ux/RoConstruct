// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <list>

// max_size 0x5d1745d = 0xffffffff / 0x2c: 44-byte element.
struct Value11 { int words[11]; bool operator==(const Value11&) const; bool operator<(const Value11&) const; };
template class std::list<Value11>;