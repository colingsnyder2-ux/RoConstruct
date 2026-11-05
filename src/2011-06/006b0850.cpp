// from server: 51% by atomic.potato
struct S
{
    void f(unsigned char value);
};

void S::f(unsigned char value)
{
    static volatile unsigned char state;
    if (state != value)
    {
        state = value;
        *(volatile unsigned long*)0x411f60 = 0xcd0340;
    }
}
