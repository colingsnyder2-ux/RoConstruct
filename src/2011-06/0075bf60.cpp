// from server: 31% by atomic.potato
struct BlockBlockContact
{
    int *getValue();
};

int *BlockBlockContact::getValue()
{
    int *value = *(int **)((char *)this + 0x2c);
    if (value != 0)
        return value;
    return 0;
}
