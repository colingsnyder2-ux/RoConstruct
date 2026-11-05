// from server: 63% by atomic.potato
struct EventDesc
{
    void f(void *);
};

extern "C" void G_00537180(void *);

void EventDesc::f(void *arg)
{
    if (arg)
        G_00537180((char *)arg - 0x1c);
    else
        G_00537180((char *)0);
}
