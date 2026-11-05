// from server: 62% by atomic.potato
extern "C" void G1_func_004c0290(void *);

struct S
{
    void *field_2c;
    void f(void *);
};

void S::f(void *p)
{
    if (p != 0)
        G1_func_004c0290((char *)field_2c + ((char *)p - (char *)0x1c));
    else
        G1_func_004c0290(field_2c);
}
