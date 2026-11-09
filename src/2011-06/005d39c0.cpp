// from server: 20% by atomic.potato
struct C { char pad[0xb0]; };

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl C_ctor(C*);
extern "C" void __cdecl C_dtor(C*);

struct S {
    void f(C* p);
};

void S::f(C* p) {
    C* q = 0;
    q = (C*)operator_new(0xb0);
    if (q) {
        C_ctor(q);
    } else {
        q = 0;
    }
    C_dtor(q);
    ((S*)p)->f(q);
}
