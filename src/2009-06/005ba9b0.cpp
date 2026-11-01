// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /GS- /MT
#include <xmemory>
struct S50 { int v[20]; };
struct S48 { int v[18]; };
template void std::_Construct<S48,S48>(S48*, const S48&);
