// from server: 74% by atomic.potato
struct S
{
    int f(unsigned char value);
    unsigned char padding[0xf9];
    unsigned char field;
};

void target(unsigned char *);

int S::f(unsigned char value)
{
    if (value != field)
    {
        field = value;
        target((unsigned char *)0x00b7b260);
    }
    return 0;
}
