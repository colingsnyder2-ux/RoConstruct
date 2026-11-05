// from server: 100% by atomic.potato
struct S
{
    int pad[3];
    int *data;
    int f(int);
};

int S::f(int index)
{
    int *p = data + index;
    while (*p == (int)p)
    {
        ++p;
        ++index;
    }
    return index;
}
