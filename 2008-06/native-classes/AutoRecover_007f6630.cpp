// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: the two 12-byte by-value structs are {function ptr, this-adjust (-332), 0} member-function-pointer-like records.
struct FnPtrRec {
    int fn;
    int adj;
    int zero;
};

// Callee takes 9 stack dwords: name, category, two 12-byte records, and a trailing int.
extern "C" int __fastcall fn_005da8b0(void* self, int unusedEdx,
                                      const char* name, const char* category,
                                      FnPtrRec first, FnPtrRec second, int flags);

// INFERRED: the two function targets stored in the records (unknown functions).
extern "C" void fn_005d7530(void);
extern "C" void fn_005dc2b0(void);

extern "C" void fn_007ff320(void);

// INFERRED: global object at 0x97a3ec constructed during static initialization.
extern "C" char g_0097a3ec[];

extern "C" void fn_007f6630(void)
{
    FnPtrRec getter = { (int)&fn_005dc2b0, -332, 0 };
    FnPtrRec setter = { (int)&fn_005d7530, -332, 0 };
    // INFERRED: dummy edx value chosen to equal the value already in edx (original is __thiscall, edx untouched)
    fn_005da8b0(g_0097a3ec, -332, "Sit", "Control", setter, getter, 4);
    atexit(fn_007ff320);
}
