// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
#include <vector>
struct P8 { int a, b; };
template P8& std::vector<P8>::operator[](size_t);
