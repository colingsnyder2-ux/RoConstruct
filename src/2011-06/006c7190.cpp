// from server: 51% by atomic.potato
// roc 2011-06 006c7190  unit: RBX::P8NetworkSettings::?$GetSetImpl  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006c7190

struct S {
    char pad0[8];
    void* (*fn)(void*);
    char pad1[4];
    void* field_c;
    void* method(void*, void*);
};

extern "C" void* __stdcall sub_a404c8(void*, void*);

void* S::method(void* a, void* b) {
    void* p = a;
    if (p) {
        p = (char*)p - 0x1c;
    } else {
        p = 0;
    }
    void* arg = (char*)field_c + (int)p;
    void* r = fn(arg);
    sub_a404c8(r, b);
    return r;
}
