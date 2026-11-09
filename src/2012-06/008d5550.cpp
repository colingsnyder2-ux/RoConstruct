// from server: 62% by atomic.potato
struct S
{
    void f(void *p);
    void *field2c;
};

extern "C" void G1_func_008d3750(void *);

void S::f(void *p)
{
    if (p)
        G1_func_008d3750((char *)field2c + ((char *)p - (char *)0) - 0x1c);
    else
        G1_func_008d3750(field2c);
}
