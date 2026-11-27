// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
void* g(const std::string&);
void* f() { std::string s(""); return g(s); }
