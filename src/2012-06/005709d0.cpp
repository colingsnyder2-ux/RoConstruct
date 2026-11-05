// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <memory>

// Element size 6 read from the target's count*6 allocation and max-count compare.
struct Elem6 { short words[3]; };
template Elem6 *std::_Allocate<Elem6>(size_t, Elem6 *);

