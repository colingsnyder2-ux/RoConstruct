// from server: 41% by atomic.potato
struct Geometry
{
    char pad0[208];
    void *data;
    char pad1[44];
    float value;
    void f(float value);
};

void Geometry::f(float value)
{
    if (value != this->value)
    {
        this->value = value;
        if (this->data)
            return;
    }
}
