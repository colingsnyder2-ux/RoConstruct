// from server: 54% by atomic.potato
extern "C" void __stdcall sub_401810(void*);

struct Inner {
    char pad0[4];
    void* p4;
    int v8;
    int v12;
    int v16;
};

struct Outer {
    void* vt;
    char pad[0x24];
    void* vt28;
    void* p2c;
    int v30;
    int v34;
    int v38;
    void* ctor(void*);
};

void* Outer::ctor(void* arg)
{
    sub_401810(arg);
    this->vt = (void*)0xa02ab4;
    Inner* inner;
    if (arg) {
        inner = (Inner*)((char*)arg + 0x28);
    } else {
        inner = 0;
    }
    this->vt28 = (void*)0xa00968;
    void* q = inner->p4;
    this->p2c = q;
    if (q) {
        void** vtbl = *(void***)q;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtbl[3];
        fn(q);
    }
    this->v30 = inner->v8;
    this->v34 = inner->v12;
    this->v38 = inner->v16;
    this->vt = (void*)0xa02d2c;
    this->vt28 = (void*)0xa02d24;
    return this;
}
