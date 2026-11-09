// from server: 50% by atomic.potato
struct CylinderBuilder
{
    void f(float* result, int value);
};

void CylinderBuilder::f(float* result, int value)
{
    ((int*)result)[0] = 0;
    int v = value >= 0 ? 6 : 2;
    ((int*)result)[1] = v;
    ((int*)result)[2] = v;
}
