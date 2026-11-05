// from server: 87% by atomic.potato
struct BoundPropGetSet
{
    int unused;
    int unused2;
    int offset;
    int getValue(void *value);
};

int BoundPropGetSet::getValue(void *value)
{
    if (value)
        return *(int *)((char *)value + offset - 28);
    return *(int *)((char *)0 + offset);
}
