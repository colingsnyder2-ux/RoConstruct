// from server: 63% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int* p = (int*)this;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    return 0;
}
