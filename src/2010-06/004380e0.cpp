// from server: 100% by atomic.potato
struct S
{
    int f(const int* a, const int* b);
};

int S::f(const int* a, const int* b)
{
    return *a == *b;
}
