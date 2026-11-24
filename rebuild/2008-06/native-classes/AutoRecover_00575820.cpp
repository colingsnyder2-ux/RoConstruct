// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout of the inner object and the owning class is unknown;
// only the accessed offsets are modeled.
struct fn_00575820_Inner {
    char pad[0x1b4];
    int state;
};

struct fn_00575820_Self {
    char pad[0x20c];
    fn_00575820_Inner* inner;
};

extern "C" bool __fastcall fn_00575820(fn_00575820_Self* self, int unusedEdx)
{
    return self->inner->state == 1;
}
