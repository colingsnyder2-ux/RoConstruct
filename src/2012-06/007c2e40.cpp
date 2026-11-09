// from server: 53% by atomic.potato
extern "C" void target7582c0(void *);

extern "C" unsigned char global_e31abe;

struct S {
    int f(int);
};

int S::f(int value)
{
    if (global_e31abe)
        return 0;

    void *p = *(void **)((char *)this + 0x84);
    void *q = (char *)p + *(int *)p + (long)this + 0x84;
    target7582c0(q);
    return value;
}
