// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: BoundProp<TextureId,1> object at 0x97bf20 (vptr at +0, owned pointer at +0x18);
// the dtor deletes the pointer and resets the vptr to the base vtable at 0x80b730.
// INFERRED: globals are modelled as raw extern slots because no native header declares the object.
#include <new>

extern void* g_0097bf20;
extern void* g_0097bf38;
extern char g_0080b730[];

extern "C" void fn_00800310(void)
{
    if (g_0097bf38)
        ::operator delete(g_0097bf38);
    g_0097bf20 = g_0080b730;
}
