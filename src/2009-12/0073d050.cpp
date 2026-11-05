// from server: 36% by atomic.potato
struct S
{
    int f(int, int, int);
};

int S::f(int a, int b, int c)
{
    int* x = a ? (int*)(a + 7) : 0;
    int* y = b ? (int*)(b + 4) : 0;
    int* v = (int*)(long)c;
    int* (*p)(int*, int*, int*) = (int* (*)(int*, int*, int*))v[1];
    return (int)p(y, x, (int*)this);
}
