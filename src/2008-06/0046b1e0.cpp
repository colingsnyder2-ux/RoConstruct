// from server: 100% by king_originala
struct A {
    char data[36];
    ~A();
};

struct B {
    ~B();
};

struct S {
    unsigned int prefix;
    A a;
    B b;
    ~S();
};

S::~S()
{
}
