// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct A { void reset(); };
struct B { void set(int); };
struct S;
int __cdecl compute(S*);
struct S {
    char pad[0x1c8];
    B b;
    char pad2[8 - 1];
    A a;
    void f();
};
void S::f() { a.reset(); b.set(compute(this)); }
