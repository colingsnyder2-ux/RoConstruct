// from server: 100% by atomic.potato
struct Job
{
    int pad0[3];
    int *items;
    int f(int index);
};

int Job::f(int index)
{
    int *p = items + index;
    while (*p == (int)p)
    {
        ++p;
        ++index;
    }
    return index;
}
