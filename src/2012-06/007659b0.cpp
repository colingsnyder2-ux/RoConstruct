// from server: 100% by tajop

void* __stdcall make_007659b0(int a, int b, int c, int d, int e, int f, int g);

struct Pair_007659b0 {
    int a;
    int b;
    Pair_007659b0() : a(0), b(0) {}
};

struct Desc_007659b0 {
    virtual void v();
};

struct DescImpl_007659b0 : Desc_007659b0 {
    int m4;
    Pair_007659b0 m8;
    DescImpl_007659b0(int x, const Pair_007659b0& p) : m4(x), m8(p) {}
    virtual void v();
};

struct Base_007659b0 {
    char pad[0x28];
    Desc_007659b0* m2c;
    Base_007659b0(void* p);
    ~Base_007659b0();
    virtual void v();
};

struct Derived_007659b0 : Base_007659b0 {
    Derived_007659b0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
    virtual void v();
};

Derived_007659b0::Derived_007659b0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
    : Base_007659b0(make_007659b0(a1, a3, a4, a5, a7, a8, a6))
{
    Desc_007659b0* p = new DescImpl_007659b0(a2, Pair_007659b0());
    Desc_007659b0* old = m2c;
    m2c = p;
    delete old;
}
