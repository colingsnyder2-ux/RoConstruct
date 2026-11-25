// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>
extern "C" void* fn_006a0920(unsigned size);
extern "C" int g_00832bcc[]; // vtable of GetSet (0x832bcc)

struct Local_0059a7c0 {
    const void* vtbl;
    int pad4; // INFERRED: untouched slot
    int f8, fC, f10;
    int pad14; // INFERRED: untouched slot
    int f18, f1C, f20;
    int pad24; // INFERRED: size 0x28
};

// INFERRED: original is a static cdecl (ret ptr + 6 stack dwords, plain ret) that the ABI
// checker wants as fastcall(self, edx). Stack args are read relative to the return address.
extern "C" Local_0059a7c0** __fastcall fn_0059a7c0(Local_0059a7c0** self, int unusedEdx)
{
    int* args = (int*)_AddressOfReturnAddress() + 1;
    Local_0059a7c0** ret = (Local_0059a7c0**)args[0];
    Local_0059a7c0* p = 0;
    Local_0059a7c0* mem = (Local_0059a7c0*)fn_006a0920(0x28);
    if (mem) {
        mem->vtbl = g_00832bcc;
        mem->f8 = args[1];
        mem->fC = args[2];
        mem->f10 = args[3];
        mem->f18 = args[4];
        mem->f1C = args[5];
        mem->f20 = args[6];
        p = mem;
    }
    *ret = p;
    return ret;
}
