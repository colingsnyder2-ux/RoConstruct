// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 8-byte value returned via out pointer (arg1); arg2 unused. Callee is SortedVertex ctor (reset of *this).
extern "C" void __fastcall fn_005428f0(void* self, int unusedEdx);

extern "C" int* __fastcall fn_00544570(int* self, int unusedEdx, int* out, int unused)
{
    int a = self[0];
    int b = self[1];
    fn_005428f0(self, 0);
    out[0] = a;
    out[1] = b;
    return out;
}
