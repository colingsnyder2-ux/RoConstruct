// from server: 49% by atomic.potato
// roc 2009-12 00642950  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00642950

extern "C" int __stdcall sub_98B768(int, int);

struct type_info {
    virtual bool operator==(const type_info&) const;
};

struct S {
    void* field0;
};

void* get(S* self) {
    void* p = self->field0;
    if (p == 0) {
        return 0;
    }
    int v;
    void* q = *(void**)p;
    if (q == 0) {
        v = 0x00b0030c;
    } else {
        v = (*(int (**)(void*))((*(int*)q) + 4))(q);
    }
    if (sub_98B768(v, 0x00b033c4) == 0) {
        return 0;
    }
    return (char*)self->field0 + 4;
}
