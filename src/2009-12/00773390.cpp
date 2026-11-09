// from server: 75% by atomic.potato
struct S
{
    void f();
    int pad0;
    int a;
    int pad1;
    int pad2;
    int c;
    int d;
    int e;
};

void S::f()
{
    c = -1;
    d = -1;
    a = 3;
    e = 3;
}
