// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: unnamed class; self+0xc is forwarded as arg1, self as arg2, result is the stack arg returned.
extern "C" int __fastcall fn_005444a0(void* self, int unusedEdx, int a1, int a2);

extern "C" void* __fastcall fn_00553850(void* self, int unusedEdx, void* out)
{
    fn_005444a0(out, 0, *(int*)((char*)self + 0xc), (int)self);
    return out;
}
