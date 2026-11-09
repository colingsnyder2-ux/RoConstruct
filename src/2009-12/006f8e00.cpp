// from server: 57% by atomic.potato
extern "C" void Function503A70(void *);

struct S
{
    int *field34;
    void f(void *);
};

void S::f(void *arg)
{
    if (arg)
        Function503A70((char *)field34 + (int)(char *)arg - 0x1c);
    else
        Function503A70(field34);
}
