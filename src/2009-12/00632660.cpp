// from server: 78% by atomic.potato
struct S
{
    unsigned char f(S *);
};

unsigned char S::f(S *p)
{
    while (p != 0 && p != this)
        p = *(S **)((char *)p + 0x4c);
    return p == this;
}
