// from server: 94% by atomic.potato
struct S
{
    int padding;
    int (__thiscall *field)(void *);
    int f(void *);
};

int S::f(void *value)
{
    int *p = (int *)value;
    if (p != 0)
    {
        p = (int *)((char *)p - 0x1c);
        if (p != 0)
            return this->field((void *)((char *)p + 0x2c0));
    }
    return this->field(0);
}
