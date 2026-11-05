// from server: 43% by atomic.potato
// roc 2009-12 00642890  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00642890

struct type_info {
    bool __thiscall operator==(const type_info&) const;
};

extern "C" {
    int __cdecl _strcmp_placeholder();
}

struct S {
    void* field0;
    void* method();
};

void* S::method() {
    void* p = field0;
    if (p == 0) {
        return 0;
    }
    type_info* ti = *(type_info**)p;
    type_info* other;
    if (ti != 0) {
        other = (type_info*)(*(void***)ti)[1];
        // call through vtable
        bool eq = ti->operator==(*(type_info*)&other);
        if (!eq) {
            return 0;
        }
    } else {
        other = (type_info*)0xb0030c;
    }
    // compare with 0xb033d0
    bool eq2 = other->operator==(*(type_info*)0xb033d0);
    if (!eq2) {
        return 0;
    }
    return (char*)field0 + 4;
}
