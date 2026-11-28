// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern (virtual-base this-adjust thunk: this -= vbase offset - 0x18, tail jump); target is a bare callee.
extern "C" void* __fastcall fn_0059c0d0(void* self);
extern "C" void* __fastcall fn_0062ccc0(char* self)
{
    return fn_0059c0d0(self - *(int*)(self - 4) - 0x18);
}
