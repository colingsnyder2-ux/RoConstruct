// from server: 100% by atomic.potato
struct S
{
    unsigned char f(void *);
    unsigned char *pad;
    unsigned char *pad2;
    unsigned char *base;
    unsigned int index;
};

unsigned char S::f(void *p)
{
    unsigned char *x;
    if (p)
        x = (unsigned char *)p - 0x1c;
    else
        x = 0;

    unsigned char *q = *(unsigned char **)(x + 0x98);
    q = *(unsigned char **)(q + index);
    q += (unsigned int)base;
    return *(unsigned char *)(q + (unsigned int)x + 0x98);
}
