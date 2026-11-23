// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: object is an opaque struct whose first dword member is set from arg1
struct fn_00553480_Obj {
    int first;
};

extern "C" fn_00553480_Obj* __fastcall fn_00553480(fn_00553480_Obj* self, int unusedEdx, int arg1, int arg2)
{
    self->first = arg1;
    return self;
}
