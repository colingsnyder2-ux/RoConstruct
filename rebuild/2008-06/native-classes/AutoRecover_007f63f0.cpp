// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: the two 12-byte by-value stack arguments look like member-function-pointer-style
// descriptors (code address, adjustor, 0), so they are modelled as a plain 3-dword struct.
struct Desc12 {
    int a;
    int b;
    int c;
};

extern "C" int __fastcall fn_005da4e0(void* self, int unusedEdx, const char* name, const char* category,
                                      Desc12 d1, Desc12 d2, int flags);

// INFERRED: the two descriptor code addresses are unknown functions in the original exe.
extern "C" void fn_005d7980(void);
extern "C" void fn_005dc150(void);

// INFERRED: the object at 0x97a328 is a global whose destructor is 0x7ff2c0 (registered via atexit).
extern "C" char g_0097a328[];
extern "C" void fn_007ff2c0(void);

extern "C" void fn_007f63f0(void)
{
    Desc12 d1 = { (int)&fn_005dc150, (int)0xfffffeb4, 0 };
    Desc12 d2 = { (int)&fn_005d7980, (int)0xfffffeb4, 0 };
    // INFERRED: the original was a __thiscall call, so edx is left holding whatever the
    // compiler had in it (the adjustor constant); pass that value as the dummy edx.
    fn_005da4e0(g_0097a328, (int)0xfffffeb4, "WalkToPart", "Control", d2, d1, 4);
    atexit(fn_007ff2c0);
}
