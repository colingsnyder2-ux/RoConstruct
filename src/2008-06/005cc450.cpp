// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct Listener {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void onChanged();
};

struct VCamera {
    char pad[0x1d8];
    int field_0x1d8;
    Listener* getListener();
    void setFlag();
};

void VCamera::setFlag() {
    if (field_0x1d8 != 1) {
        field_0x1d8 = 1;
        if (Listener* l = getListener())
            l->onChanged();
    }
}
