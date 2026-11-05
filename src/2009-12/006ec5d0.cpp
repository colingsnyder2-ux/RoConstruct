// from server: 42% by atomic.potato
struct Geometry
{
    char pad0[208];
    void* fieldD0;
    char padD4[48];
    float field104;
    void f(float value);
};

void Geometry::f(float value)
{
    if (!(value == field104))
    {
        field104 = value;
        if (fieldD0)
            reinterpret_cast<Geometry*>(fieldD0)->f(value);
    }
}
