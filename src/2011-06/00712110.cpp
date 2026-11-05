// from server: 80% by atomic.potato
struct S
{
    void f(unsigned char value);
};

extern void G1_func_00411F60();

void S::f(unsigned char value)
{
    if (*((unsigned char *)this + 0x38c) != value)
    {
        *((unsigned char *)this + 0x38c) = value;
        G1_func_00411F60();
    }
}
