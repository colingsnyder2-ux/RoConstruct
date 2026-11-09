// from server: 76% by atomic.potato
struct S
{
    void f(unsigned char value);
};

void S::f(unsigned char value)
{
    if (*(unsigned char *)((char *)this + 0x9c) != value)
    {
        *(unsigned char *)((char *)this + 0x9c) = value;
        *(unsigned long *)0x40c080 = 0xb85acc;
    }
}
