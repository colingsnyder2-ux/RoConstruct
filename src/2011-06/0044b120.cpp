// from server: 44% by atomic.potato
struct S_func_00864730 {
    char pad0[140];
    int m_x;
    int f();
};

struct S_func_00878de0 {
    char pad0[0x8c];
    int m_field_8c;
    char pad1[0xd4 - 0x90];
    void *m_field_d4;
    void f(int);
};

struct S_func_008799d0 {
    void f();
};

struct S {
    char pad0[0x20];
    char pad1[0x10c - 0x20];
    int m_field_10c;
    void f(int, int);
    void g();
};

extern "C" void __stdcall sub_00a42e00(void *);

void S::f(int a, int b)
{
    S_func_00878de0 *p = (S_func_00878de0 *)this;
    p->f(a);
    *(int *)((char *)this + 0x10c) = 0;
    *(int *)((char *)this) = 0xa6bbc4;
    *(int *)((char *)this + 0x20) = 0xa6bb64;
    *(int *)((char *)this + 0x10c) = 0xa6bb5c;
    int v = ((S_func_00864730 *)((char *)this + 0x10c))->f();
    p->f(v | 2);
    int w = ((S_func_00864730 *)((char *)this + 0x10c))->f();
    p->f(w & ~1);
    sub_00a42e00((void *)0xa6bb4c);
    ((S_func_008799d0 *)this)->f();
}
