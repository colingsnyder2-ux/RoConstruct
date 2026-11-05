// from server: 45% by atomic.potato
struct VerticalCylinderBuilder
{
    unsigned char padding[0x70];
    unsigned char field_70;
    float getValue();
};

float VerticalCylinderBuilder::getValue()
{
    static const float value_true = 1.0f;
    static const float value_false = 0.0f;
    return field_70 ? value_true : value_false;
}
