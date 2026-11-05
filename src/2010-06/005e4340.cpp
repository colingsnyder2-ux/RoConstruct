// from server: 53% by atomic.potato
struct DuplicateSelectionVerb
{
    int f();
    int *selection;
};

extern "C" int *get_selection(int *);

int DuplicateSelectionVerb::f()
{
    int *p = selection;
    if (p == 0)
        return 0;

    int *q = (int *)get_selection(p);
    if (q == 0)
        return 0;

    int *r = *(int **)((char *)q + 0x98);
    int count = (r[4] - r[3]) >> 3;
    return count > 0;
}
