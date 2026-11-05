// from server: 80% by atomic.potato
struct S
{
    unsigned char f(unsigned char* p);
    int pad;
    int value;
};

unsigned char S::f(unsigned char* p)
{
    if (p)
        return p[value - 0x1c];
    return ((unsigned char*)0)[value];
}
