// from server: 100% by colin
// from server: 95% by atomic.potato
struct S
{
    unsigned char pad[8];
    int f();
};

int S::f()
{
    if (pad[6])
        return 1;
    return pad[7] != 0 ? -1 : 0;
}