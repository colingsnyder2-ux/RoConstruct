// from server: 100% by why2
// roc 2009-06 006b2070  unit: RBX::BlockBlockContact  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b2070

extern "C" void __cdecl sub_6b4240(void*);

struct RBX_BlockBlockContact {
    char pad[8];
    void method();
};

void RBX_BlockBlockContact::method() {
    sub_6b4240((char*)this + 8);
}
