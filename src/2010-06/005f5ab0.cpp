// from server: 50% by atomic.potato
struct S
{
    typedef void (__thiscall *Callback)(void *, void *);
    void SetImpl(void *value, void *argument);
    void *field8;
    Callback fieldC;
};

void S::SetImpl(void *value, void *argument)
{
    if (value != 0)
        fieldC((char *)field8 + ((long)value - 0x1c), argument);
    else
        fieldC(field8, argument);
}
