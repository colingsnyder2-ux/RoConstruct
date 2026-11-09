// from server: 100% by atomic.potato
extern "C" void S_f(void *, void *, unsigned int);

struct S
{
    static void f(void *, void *, unsigned int);
};

void S::f(void *a, void *b, unsigned int c)
{
    if (c != 4)
    {
        c = c;
        S_f(a, b, c);
        return;
    }

    *(unsigned int *)b = 0x00d664ac;
    *((unsigned char *)b + 4) = 0;
    *((unsigned char *)b + 5) = 0;
}
