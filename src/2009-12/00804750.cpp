// from server: 100% by atomic.potato
struct S
{
    unsigned char padding[0xec];
    unsigned int value;
    void f(unsigned int a, unsigned int b);
};

void S::f(unsigned int a, unsigned int b)
{
    value = (value | a) & ~b;
}
