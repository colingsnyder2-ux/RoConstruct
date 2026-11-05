// from server: 63% by king_originala
struct S {
    void f();
    void first();
    void second();
};

void S::f()
{
    first();
    second();
}
