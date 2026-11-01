// from server: 100% by atomic.potato
struct S
{
    unsigned char padding[0x58];
    unsigned int value;
    void f(unsigned char enabled);
};

void S::f(unsigned char enabled)
{
    value = (value & 0xffffffefU) | (enabled ? 0x10U : 0U);
}
