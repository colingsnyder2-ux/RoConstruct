// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct E { std::string s; int v; };
void fillE(E* first, E* last, const E& val) { for (; first != last; ++first) *first = val; }
