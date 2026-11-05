// from server: 40% by atomic.potato
struct S
{
    int f(int);
    void *field;
};

extern "C" void target(void *);

int S::f(int value)
{
    if (value)
        target((char *)field + value - 0x1c);
    else
        target((char *)field);
    return 0;
}
