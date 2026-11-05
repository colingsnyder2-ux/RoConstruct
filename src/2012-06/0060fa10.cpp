// from server: 50% by atomic.potato
struct CylinderBuilder
{
    void f(int* result, int value);
};

void CylinderBuilder::f(int* result, int value)
{
    result[0] = 0;
    result[1] = value >= 0 ? 6 : 2;
    result[2] = value >= 0 ? 6 : 2;
}
