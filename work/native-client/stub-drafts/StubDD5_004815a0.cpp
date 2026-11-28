// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x004815a0 (scalar deleting destructor of a class with a subobject at +4: two vtable stores,
// destructor body of the subobject fn_00480120); class unknown, callee/vtables declared bare.
#include <new>
extern "C" char g_0081f314[];
extern "C" char g_0081f0f8[];
extern "C" void __fastcall fn_00480120(void* self);
extern "C" void* __fastcall fn_004815a0(char* self, int e, unsigned int f)
{
    char* sub = self + 4;
    *(void**)self = g_0081f314;
    *(void**)sub = g_0081f0f8;
    fn_00480120(sub);
    if (f & 1)
        ::operator delete(self);
    return self;
}
