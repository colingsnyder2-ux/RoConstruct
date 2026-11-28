// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x004039b0 (ATL CComClassFactory scalar deleting destructor: reset vtable, then the embedded
// CComAutoDeleteCriticalSection at +8 deletes its CRITICAL_SECTION when its initialized flag at +0x18 is set).
#include <new>
#include <windows.h>
struct AutoCS { CRITICAL_SECTION cs; char init; };
extern "C" char g_0080b168[];
extern "C" void* __fastcall fn_004039b0(char* self, int e, unsigned int f)
{
    AutoCS* c = (AutoCS*)(self + 8);
    *(void**)self = g_0080b168;
    if (c->init)
    {
        c->init = 0;
        DeleteCriticalSection(&c->cs);
    }
    if (f & 1)
        ::operator delete(self);
    return self;
}
