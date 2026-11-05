// from server: 42% by colin
// roc 2007-08 00728f90 124 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD

extern "C" void* __cdecl sub_62fef6(unsigned int size);
extern "C" void __cdecl sub_728bb0(void* dst, void* src);

struct Inner {
    int a;
    int b;
    int c;
};

struct Outer {
    int x;
    int y;
    Inner inner;
};

struct Alloc {
    int f0;
    int f1;
    Inner inner;
};

Outer* __stdcall make_outer(int a, int b, int c);

Outer* __stdcall make_outer(int a, int b, int c)
{
    Alloc* p = (Alloc*)sub_62fef6(0x1c);
    if (p) {
        p->f0 = a;
    }
    if (&p->f1) {
        p->f1 = b;
    }
    sub_728bb0(&p->inner, &c);
    return (Outer*)p;
}
