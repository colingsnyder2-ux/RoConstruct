// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Sky.h / BoundProp header shown, so layout is local: vptr, 0x18 bytes of base fields, owned pointer at +0x1c.
// INFERRED: the dtor deletes the owned pointer, then resets the vptr to the base vtable (inlined base dtor).
struct PropDescriptorBase {
    int pad[6];
    virtual ~PropDescriptorBase() {}
};

struct BoundPropTextureId : PropDescriptorBase {
    void* owned;
    virtual ~BoundPropTextureId() {
        if (owned)
            operator delete(owned);
    }
};

static BoundPropTextureId prop_SkyRt;

extern "C" void fn_00800210()
{
    prop_SkyRt.~BoundPropTextureId();
}
