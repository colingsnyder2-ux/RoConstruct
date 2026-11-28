// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: 12-byte by-value member-function-pointer-like struct {fn, this-adjust, vbtable-offset}
struct MemFnPtr12 {
    void* fn;
    int adj;
    int vb;
};

extern "C" int __fastcall fn_005da8b0(void* self, int unusedEdx,
                                      const char* a1, const char* a2,
                                      MemFnPtr12 a3, MemFnPtr12 a4, int a5);

extern "C" void fn_005dc230();
extern "C" void fn_005d7540();
// INFERRED: global object constructed in place at 0x97a5c0
extern "C" char g_0097a5c0[];
// atexit destructor stub
extern "C" void fn_007ff340();

extern "C" void fn_007f6690()
{
    // INFERRED: edx is not set up for the call in the original; the adjust value is already in edx
    int adj = -332;
    MemFnPtr12 setter;
    setter.fn = (void*)&fn_005dc230;
    setter.adj = adj;
    setter.vb = 0;
    MemFnPtr12 getter;
    getter.fn = (void*)&fn_005d7540;
    getter.adj = adj;
    getter.vb = 0;
    fn_005da8b0(g_0097a5c0, adj, "Strafe", "Control", getter, setter, 4);
    atexit((void (__cdecl *)(void))fn_007ff340);
}
