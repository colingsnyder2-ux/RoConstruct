// from server: 54% by colin
struct RefCounted {
    virtual void unknown0();
    virtual void unknown1();
    virtual void release();
};

struct CDeclarationView {
    void* vtable;
    char pad[0xf0 - 4];
    RefCounted* field_f0;
    RefCounted* field_f4;
    RefCounted* field_f8;
    RefCounted* field_fc;
    RefCounted* field_100;
    RefCounted* field_104;
    RefCounted* field_108;
    RefCounted* field_10c;

    void destroy();
};

extern "C" void __stdcall base_destructor(CDeclarationView* self);

void CDeclarationView::destroy()
{
    vtable = (void*)0x78c9c4;

    if (field_10c) {
        RefCounted* p = field_10c;
        p->release();
    }
    if (field_108) {
        RefCounted* p = field_108;
        p->release();
    }
    if (field_104) {
        RefCounted* p = field_104;
        p->release();
    }
    if (field_100) {
        RefCounted* p = field_100;
        p->release();
    }
    if (field_fc) {
        RefCounted* p = field_fc;
        p->release();
    }
    if (field_f8) {
        RefCounted* p = field_f8;
        p->release();
    }
    if (field_f4) {
        RefCounted* p = field_f4;
        p->release();
    }
    if (field_f0) {
        RefCounted* p = field_f0;
        p->release();
    }

    base_destructor(this);
}
