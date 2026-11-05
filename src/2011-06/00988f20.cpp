// from server: 53% by atomic.potato
struct VerticalCylinderBuilder
{
    float value;
    int padding[22];
    float field_5c;
    void f(float* result, int count);
};

void VerticalCylinderBuilder::f(float* result, int count)
{
    if (count > 0)
    {
        result[0] = field_5c;
        result[2] = 1;
        result[1] = 1;
    }
    else
    {
        result[0] = 0;
        result[2] = 1;
        result[1] = 1;
    }
}
