// from server: 100% by king_originala
struct Control {
    void f(int value);
};

struct Base {
    Control* f(int a1, int a2, int a3);
};

struct S : Base {
    Control* f(int a1, int a2, int a3);
};

Control* S::f(int a1, int a2, int a3)
{
    Control* result = Base::f(a1, a2, a3);
    if (a2 == 1005)
        result->f(16);
    return result;
}
