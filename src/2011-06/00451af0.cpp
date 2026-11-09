// from server: 94% by atomic.potato
struct S
{
    int pad;
    int (__thiscall *callback)(void *);
    int f(void *);
};

int S::f(void *p)
{
    int x = (int)p;
    if (x != 0)
    {
        x -= 28;
        if (x != 0)
            return callback((char *)x + 148);
    }
    return callback(0);
}
