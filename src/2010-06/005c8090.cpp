// from server: 28% by atomic.potato
extern "C" void* __cdecl sub_7a79a0(unsigned int size);
extern "C" void __fastcall sub_5c7150(void* self);

struct T {
    void sub_5c2880(void* a, void* b);
};

struct S {
    void* __cdecl f(void* arg);
};

void* S::f(void* arg) {
    void* p = sub_7a79a0(0xc8);
    void* q = 0;
    if (p) {
        sub_5c7150(p);
        q = p;
    }
    ((T*)this)->sub_5c2880(q, arg);
    return this;
}
