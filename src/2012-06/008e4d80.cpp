// from server: 80% by atomic.potato
struct S
{
    unsigned char value;
    void f(unsigned char);
};

void S::f(unsigned char value)
{
    if (*((unsigned char *)this + 0x3a4) != value)
    {
        *((unsigned char *)this + 0x3a4) = value;
        *(unsigned long *)0x414da0 = 0xe55a18;
    }
}
