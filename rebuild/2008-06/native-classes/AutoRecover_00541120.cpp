// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: object whose first dword is a pointer/handle; returns true when it is null.
struct fn_0054112_Obj {
    void* first;
};

extern "C" bool __fastcall fn_00541120(fn_0054112_Obj* self, int unusedEdx)
{
    return self->first == 0;
}
