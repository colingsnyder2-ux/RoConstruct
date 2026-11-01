// from server: 100% by king_originala
#pragma optimize("", off)

struct A {
    float& XMin();
};

struct B {};

struct S {
    S();
    void initialize(const B&, float&);
};

S::S()
{
    A a;
    B b;
    initialize(b, a.XMin());
}
