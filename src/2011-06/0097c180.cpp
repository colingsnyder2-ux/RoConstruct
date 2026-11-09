// from server: 56% by atomic.potato
struct S
{
    void f(int* a, int b);
};

void S::f(int* a, int b)
{
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    a[3] = b > 0 ? 0 : 1;
}
