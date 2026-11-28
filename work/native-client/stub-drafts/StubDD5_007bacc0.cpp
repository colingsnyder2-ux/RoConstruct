// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x007bacc0 (scalar deleting destructor of a class with a subobject at +4: two vtable stores,
// destructor body of the subobject fn_0048011a); class unknown, callee/vtables declared bare.
#include <new>
extern "C" char g_00875d54[];
extern "C" char g_00875d4c[];
extern "C" void __fastcall fn_0048011a(void* self);
extern "C" void* __fastcall fn_007bacc0(char* self, int e, unsigned int f)
{
    char* sub = self + 4;
    *(void**)self = g_00875d54;
    *(void**)sub = g_00875d4c;
    fn_0048011a(sub);
    if (f & 1)
        ::operator delete(self);
    return self;
}
