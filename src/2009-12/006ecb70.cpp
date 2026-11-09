// from server: 81% by atomic.potato
struct S
{
    int f(void *p);
    int *items;
    int count;
};

int S::f(void *p)
{
    int index;

    if (this == *(S **)((char *)p + 0x10))
        index = *(int *)((char *)p + 0x18);
    else
        index = *(int *)((char *)p + 0x1c);

    ++index;
    if (index < count)
        return items[index];

    return 0;
}
