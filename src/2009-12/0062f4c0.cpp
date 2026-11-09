// from server: 34% by atomic.potato
extern "C" void* __cdecl sub_0062ca40(int, int, int, int, int, int, int);
extern "C" void* __cdecl sub_0062f2d0(int, int);
extern "C" void __cdecl sub_007f385a(void*);
extern "C" void __cdecl sub_00444850(void*, void*);

struct S {
    void* f(int, int, int, int, int, int, int);
};

void* S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    void* p = sub_0062ca40(a1, a2, a3, a4, a5, a6, a7);
    void* q = sub_0062f2d0(a1, a2);
    sub_00444850(this, q);
    sub_007f385a(p);
    return this;
}
