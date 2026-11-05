// from server: 44% by atomic.potato
struct VerticalCylinderBuilder
{
    unsigned char padding[0x70];
    unsigned char flag;
    float getValue();
};

float VerticalCylinderBuilder::getValue()
{
    if (flag)
        return 3.1415927f;
    return 0.0f;
}
