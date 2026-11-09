// from server: 73% by atomic.potato
extern "C" void __cdecl sub_45FEF0(void*);

struct S {
    void* __cdecl f(void*);
};

void* S::f(void* p) {
    sub_45FEF0(p);
    return p;
}
