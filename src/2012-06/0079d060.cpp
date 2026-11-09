// from server: 100% by atomic.potato
extern "C" void __stdcall EventDescDispatch(unsigned long);

struct EventDesc
{
    unsigned long value;
    void Set(unsigned long);
};

void EventDesc::Set(unsigned long value)
{
    if (value != *(unsigned long *)((char *)this + 0x1f4))
    {
        *(unsigned long *)((char *)this + 0x1f4) = value;
        EventDescDispatch(0x00e49ef0);
    }
}
