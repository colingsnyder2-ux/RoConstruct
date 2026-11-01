// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
struct Elem { int v; };
template std::vector<Elem>::iterator std::vector<Elem>::erase(std::vector<Elem>::const_iterator, std::vector<Elem>::const_iterator);
