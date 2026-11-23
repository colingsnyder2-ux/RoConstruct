// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: tail-call thunk; loads member at this+0x2e4 into ecx and jumps to 0x5e9520 (thiscall on that member).
extern "C" void __fastcall fn_005e9520(void* member, int unusedEdx);

struct Fn005a0e30Self {
    char pad[0x2e4];
    void* member;
};

extern "C" void __fastcall fn_005a0e30(Fn005a0e30Self* self, int unusedEdx)
{
    fn_005e9520(self->member, 0);
}
