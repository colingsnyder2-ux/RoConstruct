// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _DLL
#include <string>
struct N { virtual void v0(); virtual const std::string& name() const; };
struct C { char pad[0x14]; N n; std::string get() const; };
std::string C::get() const { return n.name(); }
