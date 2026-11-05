// from server: 100% by atomic.potato
struct S
{
    int f();
    char padding[176];
    unsigned int value;
};

int S::f()
{
    return (value >> 2) & 1;
}
