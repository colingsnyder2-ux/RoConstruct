// from server: 100% by tajop
struct B {
    char pad[0x50];
    B();
    virtual ~B();
};

struct M {
    M(int a);
    ~M();
};

struct S : B {
    M m;
    S(int a);
    virtual ~S();
};

S::S(int a) : m(a)
{
}
