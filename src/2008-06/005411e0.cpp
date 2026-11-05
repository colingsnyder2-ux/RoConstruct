// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("g", off)

struct B {
    char pad[4];
    void f();
};

struct S {
    char pad[8];
    B b;
    ~S();
};

struct M {
    ~M();
};

struct T : S {
    M m;
    ~T();
};

T::~T()
{
}
