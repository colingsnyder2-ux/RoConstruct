// from server: 100% by why2
// roc 2009-06 004c4df0  unit: RBX::Network::Players::Plugin  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c4df0

extern "C" void* __cdecl sub_718a38(unsigned int size);

struct S {
    void* f();
};

void* S::f() {
    void* p = sub_718a38(0x44);
    if (p != 0) {
        *(void**)p = p;
    }
    void** q = (void**)((char*)p + 4);
    if (q != 0) {
        *q = p;
    }
    return p;
}
