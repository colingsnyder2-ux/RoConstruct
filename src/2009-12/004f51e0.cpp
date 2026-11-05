// from server: 28% by atomic.potato
struct S
{
    unsigned char padding[0x41];
    unsigned char value_41;
    unsigned char f();
};

unsigned char S::f()
{
    return value_41;
}
