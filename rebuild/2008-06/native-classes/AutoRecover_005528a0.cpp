// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: unknown class layout; first dword zeroed, second holds arg, subobject at +8.
struct Fn005528a0Obj {
    int field0;
    int field4;
    int sub[1];
};

extern "C" int __fastcall fn_00552f10(void* self, int unusedEdx, int a1);

extern "C" Fn005528a0Obj* __fastcall fn_005528a0(Fn005528a0Obj* self, int unusedEdx, int arg1)
{
    self->field0 = 0;
    self->field4 = arg1;
    fn_00552f10(&self->sub, 0, arg1);
    return self;
}
