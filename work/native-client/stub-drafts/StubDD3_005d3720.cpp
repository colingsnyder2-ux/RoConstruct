// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern (virtual-base this-adjust thunk: this -= vbase offset - 0x20, tail jump); target is a bare callee.
extern "C" void* __fastcall fn_0059bb10(void* self);
extern "C" void* __fastcall fn_005d3720(char* self)
{
    return fn_0059bb10(self - *(int*)(self - 4) - 0x20);
}
