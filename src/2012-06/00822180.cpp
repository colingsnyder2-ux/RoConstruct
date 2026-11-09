// from server: 65% by atomic.potato
struct S
{
    int f(int);
};

int S::f(int value)
{
    int offset;
    if (value != 0)
        offset = value - 28;
    else
        offset = 0;

    int index = *(int *)((char *)this + 16);
    int base = *(int *)((char *)this + 12);
    int table = *(int *)((char *)offset + 132);
    int target = *(int *)(table + index);
    int (*fn)(void *) = *(int (**)(void *))((char *)this + 8);

    return fn((char *)(target + base + offset + 132));
}
