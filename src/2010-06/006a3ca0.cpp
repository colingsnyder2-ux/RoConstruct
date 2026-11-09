// from server: 100% by atomic.potato
struct S
{
    char padding[0x9c];
    unsigned int value;
    void set(unsigned char enabled);
};

void S::set(unsigned char enabled)
{
    value = (value & ~4u) | ((enabled ? 1u : 0u) ? 4u : 0u);
}
