// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a thiscall adjustor thunk. It subtracts 0xc4 from `this`
// and tail-jumps to func_00568d40. No stack arguments are visible in the code.
extern "C" int __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" int __fastcall fn_0057aca0(void* self, int unusedEdx)
{
    return fn_00568d40((char*)self - 0xc4, unusedEdx);
}
