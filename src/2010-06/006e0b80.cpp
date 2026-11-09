// from server: 76% by atomic.potato
struct S
{
    char padding[0x1d0];
    int value;
    void Set(int);
};

void S::Set(int v)
{
    if (value != v)
    {
        value = v;
        *(int*)0x40c470 = 0xc20fa0;
    }
}
