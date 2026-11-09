// from server: 51% by atomic.potato
extern "C" void __stdcall call_006cb8a0(void *, void *);

struct Geometry
{
    char padding[0x90];
    int field90;
    char padding2[0x3c];
    int fieldd0;
    void setValue(int value);
};

void Geometry::setValue(int value)
{
    if (value != field90 && fieldd0 == 0)
        field90 = value;
}

struct S
{
    char padding[0x168];
    Geometry *geometry;
    void f(void *);
};

void S::f(void *value)
{
    call_006cb8a0(this, value);
    geometry->setValue(2);
}
