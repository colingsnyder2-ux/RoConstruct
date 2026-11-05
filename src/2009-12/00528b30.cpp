// from server: 71% by atomic.potato
struct S
{
    unsigned char f(unsigned char *p);
    unsigned int value;
};

unsigned char S::f(unsigned char *p)
{
    if (p)
        return p[value - 0x1c];
    return *(unsigned char *)value;
}
