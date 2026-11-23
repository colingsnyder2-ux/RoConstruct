// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout reconstructed from the disassembly only. This is a lazily
// evaluated cached 8-byte value whose getter is a member-function pointer
// with a virtual-base adjustment (adjustor at +0x14, vbtable offset at +0x18).
struct Value8 {
    float a;
    float b;
};

typedef Value8* (__thiscall *GetterFn)(void* self, Value8* out);

struct LazyValue8 {
    Value8 cached;      // +0x00
    bool   dirty;       // +0x08
    char   pad[3];
    char*  owner;       // +0x0c
    GetterFn getter;    // +0x10
    int    adjustor;    // +0x14
    int    vbtableOff;  // +0x18
};

extern "C" Value8* __fastcall fn_00656c30(LazyValue8* self, int unusedEdx, Value8* out)
{
    if (self->dirty) {
        char* owner = self->owner;
        // INFERRED: vbptr stored at owner+0x134
        char* vbptr = *(char**)(owner + 0x134);
        int vbDelta = *(int*)(vbptr + self->vbtableOff);
        void* thisPtr = owner + 0x134 + (vbDelta + self->adjustor);
        Value8 tmp;
        Value8* r = self->getter(thisPtr, &tmp);
        self->cached.a = r->a;
        self->cached.b = r->b;
        self->dirty = false;
    }
    out->a = self->cached.a;
    out->b = self->cached.b;
    return out;
}
