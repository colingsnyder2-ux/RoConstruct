// from server: 70% by atomic.potato
struct S
{
    unsigned char pad[0x9c];
    unsigned int value;
    void f(unsigned char flag);
};

void S::f(unsigned char flag)
{
    value = (value & ~4u) | ((-static_cast<int>(flag)) & 4);
}
