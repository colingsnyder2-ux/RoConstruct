// from server: 100% by atomic.potato
struct CSHA1
{
    static char f(int *a, int count, int value);
};

char CSHA1::f(int *a, int count, int value)
{
    int *p = a;
    if (*p != value)
        return 0;
    if (--count == 0)
        return 1;
    do
    {
        p++;
        if (*p != 0)
            return 0;
        if (--count == 0)
            return 1;
    } while (count != 0);
    return 1;
}
