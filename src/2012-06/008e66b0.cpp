// from server: 62% by atomic.potato
struct S
{
    char padding[216];
    float a;
    float b;
    void f(float, float);
};

void S::f(float x, float y)
{
    a = x;
    b = y;
}
