// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available, so the layouts below are
// reconstructed from the disassembly's offsets only.

struct IFloatSource {
    // INFERRED: slots 0..8 are unknown virtuals; slots 9 (+0x24) and 10 (+0x28) return float.
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual void v8() {}
    virtual float f24();
    virtual float f28();
};

struct Entry {
    char pad0[0x34];
    IFloatSource* src;
    char pad1[0x44 - 0x38];
};

struct Owner {
    char pad0[0x268];
    Entry* entries;
    int entryCount;
    char pad1[0x274 - 0x270];
    char arrA[0x280 - 0x274]; // G3D::Array<const void*> at +0x274
    char arrB[0x28c - 0x280]; // G3D::Array<const void*> at +0x280
    char arrC[12];            // G3D::Array<const void*> at +0x28c
};

// G3D::Array<const void*>::append(const void* const&)
extern "C" void __fastcall fn_00503090(void* arr, int unusedEdx, const void* const* item);

extern "C" void __fastcall fn_00503540(Owner* self, int unusedEdx)
{
    // INFERRED: comparison constant at 0x8135c4 is 0.0f
    for (int i = 0; i < self->entryCount; ++i) {
        const void* e = &self->entries[i];
        if (self->entries[i].src) {
            if (self->entries[i].src->f28() > 0.0f) {
                fn_00503090(self->arrC, 0, &e);
            } else {
                fn_00503090(self->arrA, 0, &e);
                if (self->entries[i].src->f24() > 0.0f) {
                    fn_00503090(self->arrB, 0, &e);
                }
            }
        }
    }
}
