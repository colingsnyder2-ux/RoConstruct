// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the function returns whether the first dword of the object is non-null.
struct Fn_005407e0_Obj {
    void* ptr;
};

extern "C" bool __fastcall fn_005407e0(Fn_005407e0_Obj* self, int unusedEdx)
{
    return self->ptr != 0;
}
