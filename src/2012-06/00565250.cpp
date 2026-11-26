// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void* f();
struct S4 { int v; };
struct C4 { int v; C4(const C4&); ~C4(); };
struct B1 { int x; }; struct B2 { int y; };
struct DM : B1, B2 { void fn(); };
typedef void (DM::*Fn)();
struct Obj { void* p; int q; char rest[0x3c]; Obj() : p(f()), q(0) {} Obj(const Obj&); ~Obj(); };
struct Base { Base(const char*, int, S4, S4); virtual ~Base(); char pad[0x2c]; };
struct M { int v; M() : v(0) {} ~M(); };
struct X : Base {
    Fn fn; M m38;
    X(Fn a1, const char* a3, const char* a4, int a5, S4 a6, S4 a7);
    void init(const char* a4, Obj o);
};
X::X(Fn a1, const char* a3, const char* a4, int a5, S4 a6, S4 a7) : Base(a3, a5, a6, a7), fn(a1)
{
    init(a4, Obj());
}
