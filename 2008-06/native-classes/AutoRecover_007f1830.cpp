// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

#pragma pointers_to_members(full_generality, multiple_inheritance)

// INFERRED: multiple-inheritance class so &C::m is an 8-byte member pointer (ptr, adj),
// which gives the push order name, "Data", ptr, adj, 0, 5 seen in the original.
struct B1 { virtual void a(); };
struct B2 { virtual void b(); };
struct C : B1, B2 { void m(); };

// INFERRED: thiscall member helper standing in for fn_0049aa60 (object at 0x970388).
// A member call leaves edx untouched, as the original does.
struct Obj { void run(const char* name, const char* type, void (C::*fn)(), int a, int b); };

extern Obj g_00970388; // INFERRED: global object at 0x970388
extern "C" void fn_007fb7c0();

extern "C" void fn_007f1830()
{
    g_00970388.run("LocalPlayer", "Data", &C::m, 0, 5); // INFERRED: &C::m is the function at 0x48a660
    atexit(fn_007fb7c0);
}
