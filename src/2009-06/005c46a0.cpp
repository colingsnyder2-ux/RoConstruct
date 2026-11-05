// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
#include <list>
struct Elem { int a, b; };
template std::list<Elem>::list(const std::allocator<Elem>&);
