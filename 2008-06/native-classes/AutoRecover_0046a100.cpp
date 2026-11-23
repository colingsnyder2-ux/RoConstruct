// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: cdecl with 4 stack args; ecx at the call is leftover arg3, not a real this.
extern "C" int __fastcall fn_0046a010(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, float a6);

extern "C" int fn_0046a100(int a1, int a2, int a3, int a4)
{
    return fn_0046a010((void*)a3, 0, a1, a2, a3, a4, 6, 0.0f);
}
