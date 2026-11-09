// from server: 85% by atomic.potato
struct S
{
    struct V
    {
        typedef unsigned char (__thiscall *F)(V *, void *);
        F f;
    };

    int pad[7];
    V *value;

    bool f(void *, void *);
};

bool S::f(void *a, void *b)
{
    unsigned char x = value->f(value, a);
    unsigned char y = value->f(value, b);
    return x == y;
}
