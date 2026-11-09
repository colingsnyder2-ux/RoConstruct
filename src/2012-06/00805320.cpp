// from server: 63% by atomic.potato
struct S
{
    int f(int);
    int pad[11];
    int value;
};

extern "C" void G1_func_008041f0(void *);

int S::f(int p)
{
    if (p)
        G1_func_008041f0((char *)value + p - 0x1c);
    else
        G1_func_008041f0((char *)value);
    return 0;
}
