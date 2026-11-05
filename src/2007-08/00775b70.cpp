// from server: 100% by atomic.potato
// roc 2007-08 00775b70  unit: seg_00770000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00775b70

extern "C" void __cdecl sub_630D23(void*);

struct S {
    void f();
};

struct T {
    void g(void*, void*);
};

void S::f() {
    T* p = (T*)0x8C7D7C;
    p->g((void*)0x79B670, (void*)0x7A67A8);
    sub_630D23((void*)0x77C800);
}
