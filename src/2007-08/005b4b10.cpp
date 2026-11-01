// from server: 100% by colin
struct Geometry {
    char pad[0x7c];
    int params[1];
    void setValue(int index, int value);
};

void Geometry::setValue(int index, int value)
{
    if (params[index] != value)
        params[index] = value;
}
