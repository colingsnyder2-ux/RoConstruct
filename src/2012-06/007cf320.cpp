// from server: 74% by atomic.potato
struct S
{
    unsigned char f(void *p);
    unsigned char **v0;
    int v1;
};

unsigned char S::f(void *p)
{
    unsigned char *q;
    if (p)
        q = (unsigned char *)p - 0x1c;
    else
        q = 0;
    q = (unsigned char *)((*(unsigned char ***)((char *)q + 0x84))[(unsigned int)v1] + (int)v0);
    return q[(unsigned int)p + 0x84];
}
