// from server: 95% by atomic.potato
struct S
{
    int pad0[22];
    void **items;
    int count;
    void f(void *, int);
};

void S::f(void *, int)
{
    int i = 0;
    if (count <= 0)
        return;
    do
    {
        f(items[i], 0);
        ++i;
    } while (i < count);
}
