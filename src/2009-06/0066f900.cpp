// from server: 100% by tester
struct Geometry
{
    char padding_90[0x80];
    int value_90;
    char padding_d0[0x3c];
    int value_d0;
    void setValue(int value);
};

void Geometry::setValue(int value)
{
    if (value != value_90 && value_d0 == 0)
        value_90 = value;
}
