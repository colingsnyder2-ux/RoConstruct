// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the class is unknown; the code returns whether the first dword member is non-null.
struct Unknown402410 {
    void* ptr;
};

extern "C" bool __fastcall fn_00402410(Unknown402410* self, int unusedEdx)
{
    return self->ptr != 0;
}
