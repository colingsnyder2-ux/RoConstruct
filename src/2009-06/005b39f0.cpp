// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
#include <string.h>
struct K { int a, b; char d[48]; };
struct Less { bool operator()(const K& x, const K& y) const; };
bool Less::operator()(const K& x, const K& y) const { return memcmp(x.d, y.d, 48) < 0; }
