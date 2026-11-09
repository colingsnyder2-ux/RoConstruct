// from server: 54% by atomic.potato
struct E {
    void* vf;
    char pad[8];
    int f0c;
    int f10;
    void* f14;
    int f18;
    int f1c;
    int f20;
    int f24;
};

extern "C" void __stdcall sub_b229e4(void*, void*);

struct S {
    void* vf;
    char pad[8];
    int f0c;
    int f10;
    void* f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    S* __cdecl ctor(E*);
};

S* S::ctor(E* src) {
    sub_b229e4(this, src);
    *(void**)this = (void*)0xb988dc;
    f0c = src->f0c;
    f10 = src->f10;
    f14 = (void*)0xb43e60;
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = -1;
    *(void**)this = (void*)0xb98fcc;
    f14 = (void*)0xb98fc4;
    return this;
}
