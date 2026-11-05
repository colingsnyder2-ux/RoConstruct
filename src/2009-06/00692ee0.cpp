// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Desc;
struct P0 { virtual void p0(); int a[4]; };
struct P1 { virtual void p1(); };
struct DescribedBase { virtual void d1(); const Desc* descriptor; };
struct P2 { virtual void p2(); char pad[0x68]; };
struct P3 { virtual void p3(); char pad[0x1c]; };
struct P4 { virtual void p4(); char pad[0x74]; };
struct P5 { virtual void p5(); };
struct B : P0, P1, DescribedBase, P2, P3, P4, P5 {
    B(const char* name);
};
const Desc* classDescriptor();
extern int instanceCount;
struct M { M() {} ~M(); int v; };
struct D : B {
    M m;
    D(const char* name);
};
D::D(const char* name) : B(name)
{
    descriptor = classDescriptor();
    ++instanceCount;
}
