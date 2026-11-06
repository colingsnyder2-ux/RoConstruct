// from server: 100% by tajop
struct Pad20 { char pad[0x20]; };
struct Base { int b; };
struct A : Pad20, Base { };

struct M {
    int pi;
    M(A* p, int d);
    ~M();
};

void sub_0075a4e0(M* pn, Base* pe, A* px);

struct S {
    A* px;
    M pn;
    S(A* p, int d);
};

S::S(A* p, int d) : px(p), pn(p, d)
{
    sub_0075a4e0(&pn, p, p);
}
