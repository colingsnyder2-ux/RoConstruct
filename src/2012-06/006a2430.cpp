// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
static std::string g;
extern void __cdecl cmpf(const char*, const char*, unsigned);
int f(const char* a) { cmpf(a, g.c_str(), g.size()); return 1; }