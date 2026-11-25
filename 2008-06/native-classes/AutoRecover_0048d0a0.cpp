// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this-adjust thunk (this+4) tail-calling fn_00422c60; callee takes only ecx.
extern "C" int __fastcall fn_00422c60(void* self);

extern "C" int __fastcall fn_0048d0a0(char* self)
{
    return fn_00422c60(self + 4);
}
