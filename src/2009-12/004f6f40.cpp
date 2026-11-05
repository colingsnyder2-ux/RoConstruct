// from server: 100% by atomic.potato
struct S
{
    char pad[0x50];
    int* value;

    int f();
};

int S::f()
{
    int* p = value;
    if (p)
        return (p[4] - p[3]) >> 3;
    return 0;
}
