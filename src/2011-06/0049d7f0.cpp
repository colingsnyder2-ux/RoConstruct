// from server: 35% by atomic.potato
struct Inner {
    void* p;
    void* q;
    char pad[0x18];
    char flag;
};

struct Outer {
    char pad0[4];
    Inner* inner;
    char pad1[0x18];
    void* vec;
};

extern "C" void __stdcall sub_6131f0(void* dst, void* src);
extern "C" void __stdcall sub_612f20(void* vec, unsigned int n);
extern "C" void __stdcall sub_416790(void* dst, void* a, void* b);
extern "C" void __stdcall sub_80a058(void* p);

struct S {
    void* f(void* a, void* b);
};

void* S::f(void* a, void* b)
{
    Outer outer;
    sub_6131f0(&outer, a);
    *(void**)&outer.pad0[0] = (void*)0xa5e8d0;
    sub_612f20(&outer.vec, 0);
    void* v = outer.vec;
    void* w = *(void**)v;
    void* r;
    sub_416790(&r, w, v);
    sub_80a058(outer.vec);
    return 0;
}
