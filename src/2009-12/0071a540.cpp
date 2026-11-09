// from server: 57% by atomic.potato
struct EventDesc
{
    void __cdecl f(void *);
};

void __fastcall GetSetImpl(EventDesc *, void *);

void EventDesc::f(void *arg)
{
    GetSetImpl(this, arg);
}
