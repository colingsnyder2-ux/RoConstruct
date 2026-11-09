// from server: 80% by atomic.potato
struct BoundPropGetSet
{
    int f(int *p);
    int value;
    int field;
};

int BoundPropGetSet::f(int *p)
{
    if (p)
        return *(int *)((char *)p + field - 0x1c);
    return **(int **)&field;
}
