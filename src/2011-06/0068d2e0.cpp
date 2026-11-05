// from server: 94% by atomic.potato
struct S
{
    int unused;
    int (__thiscall *function)(void *);
    int f(void *);
};

int S::f(void *value)
{
    unsigned char *p = (unsigned char *)value;
    S *object = this;

    if (p != 0)
    {
        p -= 28;
        if (p != 0)
            return object->function(p + 800);
    }

    return object->function(0);
}
