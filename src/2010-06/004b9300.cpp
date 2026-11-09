// from server: 100% by atomic.potato
extern "C" void __stdcall SetEventDescValue(unsigned int);

struct EventDesc
{
    void f(unsigned char value);
};

void EventDesc::f(unsigned char value)
{
    if (value != *(unsigned char *)((char *)this + 0xb0))
    {
        *(unsigned char *)((char *)this + 0xb0) = value;
        SetEventDescValue(0xc04838);
    }
}
