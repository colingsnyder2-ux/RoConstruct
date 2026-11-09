// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1 libs/thread/src/tss_hooks.cpp

struct S { int a, b, c; };

struct Foo { void bar(S s, int x, int y, int z, int w); };

extern "C" void f2(void*);

void func_007f67f0()
{
    S s;
    s.a = 0x5dca00;
    s.b = 0xfffffeb4;
    s.c = 0;

    Foo* thisp = (Foo*)0x97a408;
    thisp->bar(s, 0x831048, 0x83103c, 0x81c960, 0);

    f2((void*)0x7ff5c0);
}
