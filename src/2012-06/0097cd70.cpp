// from server: 100% by atomic.potato
struct S
{
    static int f(unsigned char);
};

unsigned char *g_00e02748;

int S::f(unsigned char value)
{
    if (value == *g_00e02748 || value == 10 || value == 32)
        return 1;
    return 0;
}
