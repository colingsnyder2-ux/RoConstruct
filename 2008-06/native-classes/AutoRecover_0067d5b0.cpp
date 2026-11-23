// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the callee is called cdecl with 6 pushed args (ecx is not set to an object before the call), so the thiscall declaration is not used.
extern "C" int fn_00659f60(int a1, int a2, int a3, void* p, int a3b, int flag);

extern "C" int __fastcall fn_0067d5b0(char* self, int unusedEdx, int a1, int a2, int a3)
{
    bool flag = false;
    return fn_00659f60(a1, a2, a3, self + 8, a3, flag);
}
