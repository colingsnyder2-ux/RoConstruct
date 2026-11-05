// from server: 100% by king_originala
#pragma optimize("", off)

struct S;
struct B {
    void g(int value, S* owner);
};
struct S {
    B* f(B* result, int unused, int value);
};

B* S::f(B* result, int unused, int value)
{
    result->g(value, this);
    return result;
}
