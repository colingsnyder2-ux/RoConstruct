// from server: 29% by atomic.potato
struct P8HopperBin
{
    int (__thiscall *call)(void *, void *);
    void *context;
    int (__thiscall *handler)(void *, void *);
    void SetImpl(void *, void *);
};

void P8HopperBin::SetImpl(void *value, void *arg)
{
    if (value)
        handler(context, (char *)value - 28);
    else
        handler(context, 0);
}
