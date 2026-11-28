// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00472880 (scalar deleting destructor of a class with a subobject at +4: two vtable stores,
// destructor body of the subobject fn_00471690); class unknown, callee/vtables declared bare.
#include <new>
extern "C" char g_0081e194[];
extern "C" char g_0081ce1c[];
extern "C" void __fastcall fn_00471690(void* self);
extern "C" void* __fastcall fn_00472880(char* self, int e, unsigned int f)
{
    char* sub = self + 4;
    *(void**)self = g_0081e194;
    *(void**)sub = g_0081ce1c;
    fn_00471690(sub);
    if (f & 1)
        ::operator delete(self);
    return self;
}
