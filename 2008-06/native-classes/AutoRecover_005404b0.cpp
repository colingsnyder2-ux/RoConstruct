// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly pushes no stack arguments before the call, so the callee is declared
// here with no stack args instead of the two the header hint lists. The return value is passed
// through, since eax is untouched after the call.
extern "C" int __fastcall fn_00540780(void* self, int unusedEdx);

extern "C" int __fastcall fn_005404b0(void* self, int unusedEdx)
{
    return fn_00540780((char*)self + 0xc, 0);
}
