// from server: 100% by atomic.potato
struct S
{
    char padding[0x9c];
    unsigned int value;
    int f();
};

int S::f()
{
    return (value >> 2) & 1;
}
