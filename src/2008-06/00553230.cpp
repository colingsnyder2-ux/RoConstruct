// from server: 100% by king_originala
struct S {
    S& g(int);
    void f(int);
};

#pragma optimize("", off)
void S::f(int value)
{
    g(-value);
}
