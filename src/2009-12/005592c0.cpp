// from server: 76% by atomic.potato
struct S
{
    unsigned char a[0x266f];

    char f(void* arg);
};

char S::f(void* arg)
{
    if (!a[0x266e] || !a[0x266c])
        return 0;

    struct V
    {
        char (__thiscall *g)(void*);
    };

    if (!((V*)*(void**)arg)->g(arg))
        return 1;

    return 0;
}
