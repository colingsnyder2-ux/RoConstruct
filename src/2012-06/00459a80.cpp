// from server: 44% by atomic.potato
struct XItem
{
    int *field124;
    int f(int *value, int unused);
};

int XItem::f(int *value, int unused)
{
    int *arg = value ? value + 7 : 0;
    int *p = (int *)((char *)field124 + 0x28);
    int (**fn)(int *, int *) = (int (**)(int *, int *))(*p + 3);
    return (*fn)(arg, (int *)unused);
}
