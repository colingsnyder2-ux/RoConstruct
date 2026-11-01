// from server: 100% by king_originala
struct S {
    void resize(int);
    void f();
};

#pragma optimize("", off)
void S::f()
{
    resize(0);
}
