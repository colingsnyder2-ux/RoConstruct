// from server: 80% by atomic.potato
struct S {
    void f();
};

extern "C" void __cdecl sub_007ebac0(S *);
extern "C" void sub_00414da0(S *, const char *);

void S::f()
{
    sub_007ebac0(this);
    sub_00414da0(this, (const char *)0x00e346b4);
    sub_00414da0(this, (const char *)0x00e34600);
}
