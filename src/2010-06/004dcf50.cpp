// from server: 100% by atomic.potato
struct S {
    int a;
    int pad;
    int b;
    void f();
};

void S::f()
{
    a = 0;
    b = 0;
}
