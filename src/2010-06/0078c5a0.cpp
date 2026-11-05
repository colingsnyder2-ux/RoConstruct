// from server: 77% by atomic.potato
struct Stage
{
};

struct Assembly
{
    virtual void f(Stage *) = 0;
    virtual void g() = 0;
    virtual void h() = 0;
    virtual void i() = 0;
    virtual void j(Stage *) = 0;
};

struct SpatialFilter
{
    int a;
    int b;
    Assembly *assembly;
    void f(Stage *);
};

void SpatialFilter::f(Stage *stage)
{
    assembly->j(stage);
    ((void (__thiscall *)(Assembly *, Stage *))0x750ac0)(assembly, stage);
}
