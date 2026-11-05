// from server: 28% by atomic.potato
struct S
{
    float a[16];
    void f();
};

void S::f()
{
    a[10] = 0.0f;
    a[11] = 0.0f;
    a[15] = 0.0f;
}
