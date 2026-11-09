// from server: 100% by tester
struct S {
    void resize(int);
    void f();
};

#pragma optimize("", off)
void S::f()
{
    resize(0);
}
