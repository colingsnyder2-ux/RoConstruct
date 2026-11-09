// from server: 89% by atomic.potato
struct S_func_004b8610
{
    char padding[0x50];
    int count;
    void **items;
    int f(void *);
};

int S_func_004b8610::f(void *value)
{
    int i;
    for (i = 0; i < count; ++i)
    {
        void *p = items[i];
        if (p != 0)
            p = (char *)p + 0x54;
        if (p == value)
            return i;
    }
    return -1;
}
