// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the class is unknown. The code reads a pointer at offset 0 of
// `this` and returns the address of the dword at that index, like an
// element accessor.
struct DwordArrayHolder {
    unsigned int* data;
};

// INFERRED: the dead `xor eax,eax / jne` loops in the disassembly are no-op
// compiler artifacts, so there is nothing to write for them.
extern "C" unsigned int* __fastcall fn_0054ae90(DwordArrayHolder* self, int unusedEdx, int index)
{
    return self->data + index;
}
