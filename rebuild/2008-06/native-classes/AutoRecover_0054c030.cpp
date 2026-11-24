// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the object's first dword is a pointer to an array of 0x18-byte elements,
// and the function returns the address of element [index].
// The two never-taken self-loops (xor/jne) in the disassembly have no source-level
// equivalent that survives /O2, so they are not reproduced.
struct Elem24 {
    char data[0x18];
};

struct Elem24Array {
    Elem24* items;
};

extern "C" Elem24* __fastcall fn_0054c030(Elem24Array* self, int unusedEdx, int index)
{
    return self->items + index;
}
