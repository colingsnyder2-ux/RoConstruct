// from server: 83% by atomic.potato
extern "C" void* __cdecl sub_80A05E(unsigned int);

struct T {
    void sub_94FE50(int, int, int, float);
};

struct S {
    void __cdecl f(int, int, int, float);
};

void S::f(int a, int b, int c, float d) {
    T* p = (T*)sub_80A05E(0x20);
    if (p) {
        p->sub_94FE50(a, b, c, d);
    }
}
