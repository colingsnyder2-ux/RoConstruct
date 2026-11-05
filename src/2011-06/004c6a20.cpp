// from server: 100% by atomic.potato
struct S
{
    unsigned char padding[8];
    unsigned short value;
    S *set();
};

S *S::set()
{
    value = 0xffff;
    return this;
}
