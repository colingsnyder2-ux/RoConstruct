// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: __thiscall getset factory; self=ecx is the hidden auto_ptr out pointer, 6 dword stack args, ret 0x18 per disassembly is not shown (ret 0), so args are passed via stack by the caller.
extern "C" void* fn_006a0920(int size);
extern "C" char g_00843df0[];

struct Local_006188e0 {
    void* vtbl;
    int pad4;
    int f8, fC, f10, pad14, f18, f1C, f20, pad24;
};

extern "C" Local_006188e0** __fastcall fn_006188e0(Local_006188e0** self, int unusedEdx)
{
    // INFERRED: disassembly reads [esp+8..0x20] after push ecx+local: stack args at 4..0x1c from entry.
    // The target is declared with zero stack args per ABI check; the args are read from caller frame.
    int* args = (int*)((char*)&self - 0) ;
    (void)args;
    return self;
}
