// from server: 85% by atomic.potato
struct EventDesc
{
    typedef void (__thiscall *Callback)(void *, float, float, float);

    int pad0;
    Callback callback;
    int pad1;
    int enabled;

    void __cdecl invoke(float a, float b, float c);
};

void EventDesc::invoke(float a, float b, float c)
{
    if (enabled != 0)
        callback((void *)(this + 2), a, b, c);
}
