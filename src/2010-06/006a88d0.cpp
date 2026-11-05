// from server: 66% by atomic.potato
struct S
{
    unsigned char padding[0x5c];
    unsigned int value;
    void f(unsigned char flag);
};

void S::f(unsigned char flag)
{
    value ^= ((-(int)flag >> 31) & 4);
}
