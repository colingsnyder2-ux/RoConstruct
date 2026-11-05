// from server: 87% by atomic.potato
struct S
{
    int unused;
    int unused2;
    int offset;
    unsigned char get(unsigned char* p);
};

unsigned char S::get(unsigned char* p)
{
    if (p)
        return p[offset - 0x1c];
    return ((unsigned char*)0)[offset];
}
