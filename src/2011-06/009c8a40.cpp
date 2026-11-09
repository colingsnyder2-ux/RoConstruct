// from server: 13% by atomic.potato
struct Sub {
    char pad0[4];
    int* p;
    void release();
};

struct Base {
    void* vtbl;
    char pad4[4];
    Sub sub;
    void* ptr;
    void init();
};

struct S {
    void* vtbl;
    char pad4[4];
    Sub sub;
    void* ptr;
    void dtor();
};

void Sub::release() {
    if (p) {
        extern void __stdcall dec(int*);
        dec(p);
    }
}

void Base::init() {
    sub.release();
}

void S::dtor() {
    vtbl = (void*)0xaf78b4;
    sub.release();
}
