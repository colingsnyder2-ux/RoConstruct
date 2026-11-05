// from server: 76% by atomic.potato
struct S
{
    int f(int);
};

int S::f(int p)
{
    if (((unsigned char *)this)[0x266e] &&
        ((unsigned char *)this)[0x266c])
    {
        struct V
        {
            int (__thiscall *g)();
        };

        if (!((V *)p)->g())
            return 1;
    }

    return 0;
}
