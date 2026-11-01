// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
struct V { double d[0x148 / 8]; };
typedef std::map<int, V> M;
M::iterator (M::_Mybase::*perase)(M::const_iterator) = &M::_Mybase::erase;
