// from server: 53% by atomic.potato
struct S
{
    void f(void *, void *);
};

void S::f(void *first, void *last)
{
    char *p = (char *)first;
    char *end = (char *)last;

    while (p != end)
    {
        f(p, 0);
        p += 0x58;
    }
}
