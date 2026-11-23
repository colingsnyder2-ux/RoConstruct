// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: object's first dword is a base pointer to an array of 16-byte elements; returns &base[index].
// The two dead "xor/jne" loops in the original look like a stripped assert/debug macro; not reproduced.
struct Array16 {
    char* base;
};

extern "C" char* __fastcall fn_0054bfc0(Array16* self, int unusedEdx, int index)
{
    return (char*)(index << 4) + (int)self->base;
}
