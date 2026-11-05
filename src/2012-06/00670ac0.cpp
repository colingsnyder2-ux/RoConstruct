// from server: 38% by atomic.potato
struct S
{
    void f(int, unsigned char);
};

void S::f(int value, unsigned char enabled)
{
    if (enabled)
        *(unsigned char *)((char *)this + 0x7a) = value != 2;
    else
        *(unsigned char *)((char *)this + 0x7a) = value == 1;
}
