// from server: 74% by atomic.potato
struct Geometry
{
    virtual int f0();
    virtual int f4();
    virtual int f8();
    virtual int fc();
    virtual int f10();
    virtual int f14();
    static bool check(Geometry* self);
};

bool Geometry::check(Geometry* self)
{
    if (self->f10() != 0)
    {
        int v = 10;
        return v == 9;
    }
    return self->f14() == 9;
}
