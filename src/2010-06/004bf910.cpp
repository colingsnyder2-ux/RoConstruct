// from server: 100% by atomic.potato
struct EventDesc
{
    int f();
    char padding[0x16c];
    int value_16c;
};

int EventDesc::f()
{
    if (value_16c == 0 || value_16c == 2)
        return 1;
    return 0;
}
