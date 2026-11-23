// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_005444a0(void* self, int unusedEdx, int a1, int a2);

// INFERRED: __thiscall, ecx = this; passes (this->field10, this) to helper with ecx = arg1, returns arg1.
extern "C" int __fastcall fn_0054c1d0(void* self, int unusedEdx, int arg1)
{
    int field10 = *(int*)((char*)self + 0x10);
    fn_005444a0((void*)arg1, 0, field10, (int)self);
    return arg1;
}
