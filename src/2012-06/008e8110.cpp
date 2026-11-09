// from server: 94% by atomic.potato
struct FactoryProduct
{
    int a;
    int b;
    int pad[4];
    int c;
    int d;
    int pad2[24];
    int e;
    int f;
    void method();
};

void FactoryProduct::method()
{
    a = 0xbed42c;
    b = 0xbed420;
    c = 0xbed414;
    d = 0xbed408;
    e = 0xbed3f8;
    f = 0xbed3cc;
}
