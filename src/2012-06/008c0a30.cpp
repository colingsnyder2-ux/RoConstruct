// from server: 32% by atomic.potato
struct Stepped;

struct Alloc {
    void* f0;
    void* f4;
    void* f8;
    void* fc;
    void* f10;
    void* f14;
    void* f18;
};

extern "C" void* __cdecl sub_4287B0(unsigned int);
extern "C" void __cdecl sub_428700(void*);

struct Base {
    void sub_8C07A0(void*);
};

struct Stepped {
    void* sub_8C0A30(void** out, void* arg);
};

void* Stepped::sub_8C0A30(void** out, void* arg) {
    Alloc* p = (Alloc*)sub_4287B0(0x1c);
    if (p) {
        p->f8 = (void*)0xbe5bb0;
        p->fc = 0;
        p->f0 = (void*)0xbe5bc0;
        p->f8 = (void*)0xbe5bb8;
        p->f10 = this;
        p->f14 = *(void**)arg;
        p->f18 = *((void**)arg + 1);
        p->f0 = (void*)0xbe5bd8;
        p->f8 = (void*)0xbe5bd0;
    }
    ((Base*)this)->sub_8C07A0(p);
    *out = p;
    if (p) {
        sub_428700((char*)p + 5);
    }

    return this;
}
