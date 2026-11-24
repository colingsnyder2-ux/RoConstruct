// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjustor thunk (thiscall): ecx -= 0x150, then tail-jump
// to the primary implementation at 0x00568d40. The return type and any stack
// arguments are unknown; none are modelled here.
extern "C" int __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" int __fastcall fn_0057a840(char* self, int unusedEdx)
{
    return fn_00568d40(self - 0x150, unusedEdx);
}
