// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _DLL
#include <stdexcept>
std::runtime_error runtime_error(const char* fmt, ...);
void bad(int, const char* name) { throw runtime_error("%s is not a valid member", name); }
