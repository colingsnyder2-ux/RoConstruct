// from server: 38% by atomic.potato
struct S
{
    int a;
    int b;
    unsigned char c;
    float d;
    S *f(int, int);
};

S *S::f(int x, int y)
{
    a = x;
    b = y;
    c = 1;
    d = 0.0f;
    return this;
}
