// from server: 75% by atomic.potato
struct S
{
    int value;
    unsigned char padding[172];
    unsigned char enabled;
    unsigned char padding2[183];
    int state;
    unsigned char get(S* other);
};

unsigned char S::get(S* other)
{
    if (!other->enabled)
        return 0;
    return other->state != state;
}
