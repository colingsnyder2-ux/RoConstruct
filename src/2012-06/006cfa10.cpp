// from server: 100% by tester
struct S
{
    unsigned char padding[0xce0];
    unsigned int flags;
    int get(unsigned int);
};

int S::get(unsigned int index)
{
    return (flags & (1u << index)) != 0;
}