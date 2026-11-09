// from server: 94% by atomic.potato
struct S
{
    int reserved;
    int (__thiscall *func)(void *);
    int f(void *);
};

int S::f(void *value)
{
    if (value)
    {
        char *p = (char *)value - 0x1c;
        if (p)
            return this->func(p + 0x19c);
    }
    return this->func(0);
}
