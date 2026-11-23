// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// The original calls through the MSVCR90 import (IAT pointer loaded into ebp).
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: this looks like a checked-iterator std::vector::erase(first, last).
// The object has a proxy pointer at +0, begin at +0xC and end at +0x10.
struct RbxVecLike {
    unsigned proxy;     // +0x00
    unsigned pad4;      // +0x04
    unsigned pad8;      // +0x08
    unsigned begin;     // +0x0C
    unsigned end;       // +0x10
};

extern "C" int __fastcall fn_0068e150(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6);

extern "C" unsigned* __fastcall fn_00697c10(RbxVecLike* self, int unusedEdx,
                                            unsigned* ret, int firstProxy, unsigned first,
                                            int lastProxy, unsigned last)
{
    ret[0] = 0;
    if (!self || self->begin > first || first > self->end)
        _invalid_parameter_noinfo();
    ret[0] = self->proxy;
    ret[1] = first;

    if (self->begin > last || last > self->end)
        _invalid_parameter_noinfo();

    if (ret[0] == 0 || ret[0] != self->proxy)
        _invalid_parameter_noinfo();

    if (ret[1] != last) {
        // INFERRED: the dummy dword is an (empty) tag argument pushed three times.
        int dummy = 0;
        self->end = (unsigned)fn_0068e150((void*)ret[1], 0, (int)last, (int)self->end,
                                          (int)ret[1], dummy, dummy, dummy);
    }
    return ret;
}
