// from server: 100% by atomic.potato
struct S
{
    unsigned char padding[0xcd0];
    unsigned int flags;
    int get(unsigned int);
};

int S::get(unsigned int index)
{
    return (flags & (1u << index)) != 0;
}
