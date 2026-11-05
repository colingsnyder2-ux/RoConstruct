// from server: 100% by king_originala
#include <intrin.h>
// roc 2008-06 005a0220  unit: RBX::Workspace  size: 32 bytes

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Target { void run(); };
struct Inner {
    virtual void slot0();
    virtual Target* slot1(int);
};
struct S {
    char padding[0x288];
    Inner inner;
    void f(volatile int);
};
void S::f(volatile int a)
{
    int argument = a;
    _ReadWriteBarrier();
    inner.slot1(argument)->run();
}
