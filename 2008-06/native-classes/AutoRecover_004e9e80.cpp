// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout and types are guesses. The object has a dword at +0 that is
// first zeroed and then overwritten with a constant (probably a vtable pointer)
// on the failure path. An 8-byte payload sits at +8.
struct Fn4e9e80Obj {
    int tag;
    int pad;
    int payload[2];
};

// INFERRED: unknown global whose address is stored at +0 (vtable / type tag).
extern "C" char g_00826ea8[];

// INFERRED: the 8-byte local holds {arg1, arg2} on entry, and its address is passed
// to StringConverter<CoordinateFrame>::convertToValue. That callee is
// declared here as a plain cdecl extern because no header was available.
extern "C" bool fn_0060a2f0(int* inout);

extern "C" Fn4e9e80Obj* __fastcall fn_004e9e80(Fn4e9e80Obj* self, int unusedEdx, int arg1, int arg2, int arg3)
{
    int local[2];
    local[0] = arg1;
    local[1] = arg2;
    self->tag = 0;
    if (!fn_0060a2f0(local)) {
        // INFERRED: the original null-checks &self->payload (placement-new style), which is always true.
        self->payload[0] = local[0];
        self->payload[1] = local[1];
        self->tag = (int)g_00826ea8; // INFERRED: vtable/type-tag address
        return self;
    }
    self->tag = 0;
    return self;
}
