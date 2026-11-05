// from server: 76% by atomic.potato
struct S
{
    unsigned char value;
    void f(unsigned char);
};

void S::f(unsigned char value)
{
    if (value != *(unsigned char *)((char *)this + 0xf7))
    {
        *(unsigned char *)((char *)this + 0xf7) = value;
        *(unsigned int *)((char *)0x40c080) = 0xb7b220;
    }
}
