// from server: 61% by atomic.potato
struct EventDesc
{
    void (__thiscall *handler)(EventDesc *, float, float);

    void __cdecl invoke(float a, float b, EventDesc *context);
};

void EventDesc::invoke(float a, float b, EventDesc *context)
{
    handler(this, a, b);
}
