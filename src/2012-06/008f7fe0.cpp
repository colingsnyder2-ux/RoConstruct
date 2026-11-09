// from server: 95% by atomic.potato
struct S
{
    int padding[4];
    int active;
};

struct EventDesc
{
    int vtable;
};

typedef void (__thiscall *Callback)(void *, float, float, float);

void func_008f7fe0(S *track, float a, float b, float c)
{
    if (track->active != 0)
    {
        EventDesc *event = (EventDesc *)((char *)track + 8);
        Callback callback = *(Callback *)*(void **)event;
        callback(event, c, b, a);
    }
}
