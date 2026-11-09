// from server: 88% by atomic.potato
struct S
{
    unsigned char field00[0x58];
    unsigned int field58;
    void set(int value);
};

void S::set(int value)
{
    unsigned int x = value ? 0u : 4u;
    field58 = (field58 & 0xfffffffbU) | x;
}
