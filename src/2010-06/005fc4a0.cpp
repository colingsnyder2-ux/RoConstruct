// from server: 100% by atomic.potato
struct S
{
    int f();
    char padding[0x164];
    int value;
};

int S::f()
{
    return value >= 5;
}
