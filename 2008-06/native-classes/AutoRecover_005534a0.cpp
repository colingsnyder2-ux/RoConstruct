// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: simple constructor-like function storing its argument at offset 0 and returning this
struct Fn_005534a0_Obj {
    int value;
};

extern "C" Fn_005534a0_Obj* __fastcall fn_005534a0(Fn_005534a0_Obj* self, int unusedEdx, int arg1)
{
    self->value = arg1;
    return self;
}
