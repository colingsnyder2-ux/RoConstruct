// from server: 31% by atomic.potato
struct ConstraintSurfacePair
{
    int type;
    int surface1;
    int surface2;
    int value1;
    int value2;
    void Set(int a, int b, int c, int d);
};

void ConstraintSurfacePair::Set(int a, int b, int c, int d)
{
    surface1 = a;
    surface2 = c;
    type = 0xABD07C;
    value1 = *reinterpret_cast<int *>(b);
    value2 = *reinterpret_cast<int *>(d);
    type = 0xABD0BC;
}
