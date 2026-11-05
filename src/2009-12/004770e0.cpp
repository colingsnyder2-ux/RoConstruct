// from server: 100% by atomic.potato
struct S
{
    int f(int* p);
};

int S::f(int* p)
{
    ++p[2];
    return p[2];
}
