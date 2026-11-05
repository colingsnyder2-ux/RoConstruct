// from server: 100% by atomic.potato
struct BlockBlockContact
{
    int *getValue();
};

int *BlockBlockContact::getValue()
{
    int *value = *(int **)((char *)this + 0x2c);
    if (value == 0)
        return 0;
    return *(int **)((char *)value + 0x20);
}
