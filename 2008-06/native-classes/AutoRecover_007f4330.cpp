// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: the two by-value 12-byte arguments are small POD structs whose first
// dword is a constant pointer into .rdata and whose other two dwords are zero.
struct RocArgA {
    const void* p;
    int a;
    int b;
};

struct RocArgB {
    const void* p;
    int a;
    int b;
};

extern "C" char g_0059d8a0[];
extern "C" char g_00598cb0[];
extern "C" char g_00976198[];

extern "C" int __fastcall fn_0059c860(void* self, int unusedEdx,
                                      const char* name, const char* member,
                                      RocArgB b, RocArgA a, int flags);

// INFERRED: static destructor registered with atexit
extern "C" void fn_007fdd90(void);

extern "C" void fn_007f4330(void)
{
    RocArgA a = { g_0059d8a0, 0, 0 };
    RocArgB b = { g_00598cb0, 0, 0 };
    fn_0059c860(g_00976198, 0, "CFrame", "Data", b, a, 5);
    atexit(fn_007fdd90);
}
