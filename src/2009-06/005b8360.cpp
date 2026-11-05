// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
#include <memory>
struct S58 { char d[0x58]; };
template S58* std::_Allocate<S58>(size_t, S58*);
