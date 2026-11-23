// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: class names and layouts are unknown; these file-local types only
// reproduce the member offsets and the RTTI dynamic_cast used by the target.
struct RbxBaseObj {
    virtual void anchor() = 0;
};

struct RbxDerivedObj : public RbxBaseObj {
    char pad0[0x1e8 - 4];
    float valueA;           // +0x1e8
    char pad1[0x328 - 0x1ec];
    float valueB;           // +0x328
};

struct RbxOwner {
    char pad[0x104];
    RbxBaseObj* target;     // +0x104
};

extern "C" float __fastcall fn_0059eca0(RbxOwner* self, int unusedEdx)
{
    if (self->target) {
        RbxDerivedObj* d = dynamic_cast<RbxDerivedObj*>(self->target);
        if (d) {
            return 1.0f - (1.0f - d->valueA) * d->valueB;
        }
    }
    return 0.0f;
}
