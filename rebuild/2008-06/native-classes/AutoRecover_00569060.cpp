// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this-adjusting thunk (secondary base at +0x24 -> primary); callee is __thiscall with no stack args, return type unknown.
extern "C" void __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" void __fastcall fn_00569060(char* self, int unusedEdx)
{
    fn_00568d40(self - 0x24, unusedEdx);
}
