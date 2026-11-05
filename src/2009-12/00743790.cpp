// from server: 76% by atomic.potato
struct S
{
    char padding[172];
    int value;
    void f(int);
};

void S::f(int v)
{
    if (value != v)
    {
        value = v;
        *(int**)0x00b96cf4 = (int*)0xb96cf4;
        return;
    }
}
