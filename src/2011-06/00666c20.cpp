// from server: 100% by atomic.potato
struct S
{
    unsigned char pad[4];
    unsigned char enabled;
    unsigned char value;
    int f();
};

int S::f()
{
    if (enabled)
        return 1;
    return value != 0 ? -1 : 0;
}
