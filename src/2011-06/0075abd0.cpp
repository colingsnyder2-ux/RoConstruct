// from server: 100% by atomic.potato
struct BlockBlockContact
{
    int getValue(int index);
};

int BlockBlockContact::getValue(int index)
{
    int *value = *(int **)((char *)this + 0x2c);
    if (value == 0)
        return 0;
    return value[index];
}
