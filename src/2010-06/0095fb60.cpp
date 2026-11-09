// from server: 84% by atomic.potato
struct CylinderBuilder
{
    void f(int *p, int value);
};

void CylinderBuilder::f(int *p, int value)
{
    p[0] = 0;
    int n = 6;
    if (value < 0)
        n = 2;
    p[1] = n;
    p[2] = n;
}
