// from server: 100% by atomic.potato
struct S
{
    unsigned int a;
    unsigned int c;
    unsigned int b;
    unsigned char *d;
    unsigned char f(unsigned char *out);
};

unsigned char S::f(unsigned char *out)
{
    unsigned int p = b + 8;
    if (p > a)
        return 0;

    *out = d[b >> 3];
    b += 8;
    return 1;
}
