// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
#include <fstream>
void destroy_ifs(std::ifstream* p) { delete p; }
std::ifstream* make_ifs() { return new std::ifstream("x"); }
