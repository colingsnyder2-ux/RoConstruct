// from server: 49% by atomic.potato
struct VerticalCylinderBuilder
{
    void GetValue(float *result, int count);
    char padding[92];
    float value;
};

void VerticalCylinderBuilder::GetValue(float *result, int count)
{
    if (count > 0)
    {
        result[0] = value;
        result[1] = 1;
        result[2] = 1;
    }
    else
    {
        result[0] = 0;
        result[1] = 1;
        result[2] = 1;
    }
}
