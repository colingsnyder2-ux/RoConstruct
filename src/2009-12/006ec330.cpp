// from server: 100% by atomic.potato
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
