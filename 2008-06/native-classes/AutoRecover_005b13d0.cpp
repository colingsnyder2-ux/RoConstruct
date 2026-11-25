// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: actual ABI is cdecl, out-pointer first plus 6 value args (ret 0), not thiscall.
// INFERRED: layout of the 0x28-byte product; vtable at 0x834b20 comes from the disassembly.
struct Local_005b13d0 {
    virtual void f0();
    int pad4;
    int a8, aC, a10;
    int pad14;
    int a18, a1C, a20;
    int pad24;
};

extern "C" void* fn_006a0920(unsigned size);

extern "C" Local_005b13d0** fn_005b13d0(Local_005b13d0** out, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Local_005b13d0* p = 0;
    void* mem = fn_006a0920(0x28);
    if (mem) {
        p = (Local_005b13d0*)mem;
        // vtable store 0x834b20 implied by virtual class; INFERRED
        p->a8 = a2;
        p->aC = a3;
        p->a10 = a4;
        p->a18 = a5;
        p->a1C = a6;
        p->a20 = a7;
        *out = p;
        return out;
    }
    *out = 0;
    return out;
}
