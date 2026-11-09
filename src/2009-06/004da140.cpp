// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
struct V { char d[0x150]; };
typedef std::map<int, V> M;
void (M::const_iterator::*pdec)() = &M::const_iterator::_Dec;
