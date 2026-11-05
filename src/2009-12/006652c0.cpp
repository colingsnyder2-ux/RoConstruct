// from server: 91% by atomic.potato
extern "C" long __stdcall InterlockedDecrement(long *);

struct EventDesc
{
    void f();
};

void EventDesc::f()
{
    *(long *)this = 0x009ce7f8;
    InterlockedDecrement((long *)0x00b99168);
}
