// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this-pointer adjustor thunk. The original moves the object pointer
// back by 0x64 bytes and tail-jumps to the real implementation at 0x568d40.
// The target is declared __cdecl to match the required ABI (plain ret, caller pops).
// The callee receives the adjusted pointer in ecx, so it is declared __fastcall.
extern "C" int __fastcall fn_00568d40(char* self);

extern "C" int __cdecl fn_00568d10(char* self)
{
    return fn_00568d40(self - 0x64);
}
