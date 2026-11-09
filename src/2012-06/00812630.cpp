// from server: 79% by atomic.potato
extern void G1_func_00811a80();

struct S
{
    void f();
    int a;
    int b;
    int c;
    int d;
    int e;
};

void S::f()
{
    a = 0xbc671c;
    b = 0xbc6710;
    c = 0xbc6704;
    d = 0xbc66f8;
    e = 0xbc66cc;
    G1_func_00811a80();
}
